#include <string>
#include <iostream>
#include <zmq.hpp>

#include <chrono>
#include <thread>
int main() {
    using namespace std::chrono_literals;
    zmq::context_t context{1};
    zmq::socket_t publisher{context, zmq::socket_type::pub};
    publisher.bind("tcp://*:5555");
    while(1) {
        publisher.send(zmq::str_buffer("hello world"), zmq::send_flags::sndmore);
        publisher.send(zmq::str_buffer("Message in A envelope"));


        publisher.send(zmq::str_buffer("B"), zmq::send_flags::sndmore);
        publisher.send(zmq::str_buffer("Message in B envelope"));


        publisher.send(zmq::str_buffer("C"), zmq::send_flags::sndmore);
        publisher.send(zmq::str_buffer("Message in B envelope"));

        std::this_thread::sleep_for(1s);
    }
    return 0;
}