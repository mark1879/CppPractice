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
            // 三种情况下会返回: 1. 缓冲区满； 2. transfer_at_least为真（收到特定数量字节即返回）；3. 有错误发生
            async_read(socket_, buffer(buffer_), transfer_at_least(kHeaderLength), [this](const boost::system::error_code& error, size_t size)
           {
               if (error.failed())
               {
                   HandleError(error);
                   return;
               }
               
               cout << buffer_.data() + kHeaderLength << endl;
               
               HandleRead();
           });
        }
        
        void HandleWrite(const char* data, int len)
        {
            boost::system::error_code error;
            
            write(socket_, buffer(data, len), error);
            if (error.failed())
            {
                HandleError(error);
            }
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
