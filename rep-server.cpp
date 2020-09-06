#include <string>
#include <iostream>
#include <zmq.hpp>
int main() {
    zmq::context_t context{1};
    zmq::socket_t socket{context, zmq::socket_type::rep};
    socket.bind("tcp://*:5555");
    while(1) {
        zmq::message_t request;
        auto res = socket.recv(request);
        socket.send(zmq::const_buffer());
        std::cout << "Received " << request.to_string() << std::endl;
    }
    return 0;
}