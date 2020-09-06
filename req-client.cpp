#include <string>
#include <iostream>
#include <zmq.hpp>

int main() {
    zmq::context_t context{1};
    zmq::socket_t socket{context, zmq::socket_type::req};
    socket.connect("tcp://localhost:5555");
    const std::string data{"Hello World!"};
    socket.send(zmq::buffer(data));
    return 0;
}
