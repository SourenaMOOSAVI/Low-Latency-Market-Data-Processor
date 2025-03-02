#ifndef UDPSERVER_HPP
#define UDPSERVER_HPP

#include <boost/asio.hpp>
#include <string>
#include <thread>
#include <atomic>

class UDPServer {
public:
    UDPServer(const std::string& ip, int port);
    ~UDPServer();

    void start(); // Start the server
    void stop();  // Stop the server
    void sendData(const std::string& message, const std::string& dest_ip, int dest_port);

private:
    void run();   // Main server loop

    boost::asio::io_context io;
    boost::asio::ip::udp::socket socket;
    boost::asio::ip::udp::endpoint server_endpoint;
    boost::asio::ip::udp::endpoint remote_endpoint;
    std::thread server_thread;
    std::atomic<bool> running{false};
};

#endif // UDPSERVER_HPP
