//
//  read_write_handler.hpp
//  BoostPractice
//
//  Created by MarkWu on 2019/7/25.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef read_write_handler_h
#define read_write_handler_h

#include <array>
#include <functional>
#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

namespace boost_practice
{
    const int kMaxIpPacketSize = 65536;
    const int kHeaderLength = 4;
    
    class RWHandler
    {
    public:
        RWHandler(io_service& service) : socket_(service)
        {
        }
        
        ~RWHandler()
        {
        }
        
        void HandleRead()
        {
            async_read(socket_, buffer(buffer_), transfer_at_least(kHeaderLength), [this](const boost::system::error_code& error, size_t size)
           {
               if (error)
               {
                   HandleError(error);
                   return;
               }
               
               cout << buffer_.data() + kHeaderLength << endl;
               
               HandleRead();
           });
        }
        
        void HandleWrite()
        {
            
        }
        
        tcp::socket& GetSocket()
        {
            return socket_;
        }
        
        void CloseSocket()
        {
            boost::system::error_code error;
            socket_.shutdown(tcp::socket::shutdown_send, error);
            socket_.close(error);
        }
        
        void SetConnectID(int connect_id)
        {
            connect_id_ = connect_id;
        }
        
        int GetConnectID() const
        {
            return connect_id_;
        }
        
        template<typename F>
        void SetCallBackError(F f)
        {
            callback_ = f;
        }
        
    private:
        
        void HandleError(const boost::system::error_code& error)
        {
            CloseSocket();
            
            cout << error.message() << endl;
            
            if (callback_)
            {
                callback_(connect_id_);
            }
        }
        
    private:
        tcp::socket socket_;
        std::array<char, kMaxIpPacketSize> buffer_;
        std::function<void(int)> callback_ = nullptr;
        int connect_id_;
    };
}

#endif /* read_write_handler_h */
