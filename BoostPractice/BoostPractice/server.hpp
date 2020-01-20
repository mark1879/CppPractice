//
//  server.hpp
//  BoostPractice
//
//  Created by MarkWu on 2019/7/25.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef server_h
#define server_h

#include <boost/asio/buffer.hpp>
#include <boost/unordered/unordered_map.hpp>
#include "read_write_handler.hpp"

namespace boost_practice
{
    const int kMaxConnectionCount = 65536;
    const int kMaxReceiveSize = 65536;
    
    class Server
    {
    public:
        Server(io_service& service, short port) : io_service_(service), acceptor_(service, tcp::endpoint(tcp::v4(), port)), connect_id_pool_(kMaxConnectionCount)
        {
            int initial_connect_id = 0;
            std::generate_n(connect_id_pool_.begin(), kMaxConnectionCount, [&initial_connect_id] { return ++initial_connect_id; });
        }
        
        ~Server()
        {
            
        }
        
        void Accept()
        {
            cout << "[Server::Accept], start listening" << endl;
            
            std::shared_ptr<RWHandler> handler = CreateHandler();
            
            acceptor_.async_accept(handler->GetSocket(), [this, handler](const boost::system::error_code& error){
                if (error.failed())
                {
                    HandleAcceptError(handler, error);
                }
            });
        }
        
    private:
        void HandleAcceptError(std::shared_ptr<RWHandler> handler, const boost::system::error_code& error)
        {
            cout << "[Server::HandleAcceptError], value: " << error.value() << ", message:" << error.message() << endl;
            
            handler->CloseSocket();
            StopAccept();
        }
        
        void StopAccept()
        {
            boost::system::error_code error;
            acceptor_.cancel(error);
            acceptor_.close(error);
            io_service_.stop();
        }
        
        std::shared_ptr<RWHandler> CreateHandler()
        {
            int connect_id = connect_id_pool_.front();
            connect_id_pool_.pop_front();
            
            std::shared_ptr<RWHandler> handler = std::make_shared<RWHandler>(io_service_);
            handler->SetConnectID(connect_id);
            
            handler->SetCallBackError([this] (int connect_id){
                RecycleConnectID(connect_id);
            });
            
            return handler;
        }
        
        void RecycleConnectID(int connect_id)
        {
            auto it = handlers_.find(connect_id);
            
            if (it != handlers_.end())
            {
                handlers_.erase(it);
            }
            
            cout << "[Server::RecycleConnectID], current connect count: " << handlers_.size() << endl;
            
            connect_id_pool_.push_back(connect_id);
        }
        
    private:
        io_service& io_service_;
        tcp::acceptor acceptor_;
        boost::unordered_map<int, std::shared_ptr<RWHandler>> handlers_;
        list<int> connect_id_pool_;
    };
        
}

#endif /* server_h */
