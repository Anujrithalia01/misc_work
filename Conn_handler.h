#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <string>
#include<queue>
#include <nlohmann/json.hpp>
#include "Game.h"


namespace asio = boost::asio;
namespace ip = asio::ip;
using namespace nlohmann;

class Conn_handler : public boost::enable_shared_from_this<Conn_handler>
{
private:
    ip::tcp::socket socket;
    enum { max_length = 1024 };
    std::string return_data;
    char received_data[max_length];
    //std::string return_data;

    std::queue<std::string> request_queue;


    // Process the received HTTP request
    void process_http_request(const std::string& request);

    // Send the response for the processed HTTP request
    void send_http_response(const std::string& response);

    // Read the incoming data from the socket
    void read_data(const boost::system::error_code&, size_t);

    //Various request Handlers
    void create_room(json);
    void get_legal_moves(json);
    void update_board(json);
    void validate_check(json);
    void undo(json);
    Game* game;

public:
    typedef boost::shared_ptr<Conn_handler> pointer;
    Conn_handler(boost::asio::io_context& io_context, Game* game) : socket(io_context) {
        this->game = game;
    }

    // creating the pointer
    static pointer create(boost::asio::io_context& io_context, Game* game)
    {
        return pointer(new Conn_handler(io_context, game));
    }
    //socket creation
    ip::tcp::socket& getSocket();

    void start();

};