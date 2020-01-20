//
//  main.cpp
//  BoostPractice
//
//  Created by MarkWu on 2019/7/19.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <boost/asio.hpp>
#include <iostream>
#include "server.hpp"
#include "client.hpp"
#include "read_write_handler.hpp"

int main()
{
    boost::asio::io_service io_service;
    
    boost_practice::Server server(io_service, 9900);
    server.Accept();
    io_service.run();
    
    return 0;
}
