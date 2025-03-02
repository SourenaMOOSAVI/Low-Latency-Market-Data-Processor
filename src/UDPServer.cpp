#include "UDPServer.hpp"
#include <iostream>

UDPServer::UDPServer(const std::string& ip, int port)
    : socket(io, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
      server_endpoint(boost::asio::ip::make_address(ip), port) {}

UDPServer::~UDPServer() {
    stop();
}

void UDPServer::start() {
    running.store(true);
    server_thread = std::thread(&UDPServer::run, this);
}

void UDPServer::stop() {
    running.store(false);
    socket.close();
    if (server_thread.joinable()) {
        server_thread.join();
    }
}

void UDPServer::run() {
    char buffer[1024];
    while (running.load()) {
        boost::system::error_code error;
        std::size_t len = socket.receive_from(boost::asio::buffer(buffer), remote_endpoint, 0, error);
        if (!error) {
            std::cout << "Received: " << std::string(buffer, len) << std::endl;
        }
    }
}

void UDPServer::sendData(const std::string& message, const std::string& dest_ip, int dest_port) {
    boost::system::error_code error;
    boost::asio::ip::udp::endpoint dest_endpoint(boost::asio::ip::make_address(dest_ip), dest_port);
    
    socket.send_to(boost::asio::buffer(message), dest_endpoint, 0, error);

    if (error) {
        std::cerr << "Error sending data: " << error.message() << std::endl;
    }
}
