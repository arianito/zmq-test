#include <string>
#include <iostream>
#include <future>
#include <zmq.hpp>

void load_subscriber(zmq::context_t *ctx, const char* channel) {
    zmq::socket_t subscriber{*ctx, zmq::socket_type::sub};
    subscriber.connect("tcp://localhost:5555");
    subscriber.set(zmq::sockopt::subscribe, channel);
   	int sts = 0;
    while(1) {
        zmq::message_t message;
        if(subscriber.recv(message).has_value()) {
	        auto value = message.to_string();
	        if(value.compare(channel) == 0) {
	        	if(sts == 0) {
	        		sts = 1;
	        	}
	        } else if(sts == 1) {
		    	std::cout << value << std::endl;
		    	sts = 0;
		    }
	    } else {
	    	sts = 0;
	    }
    }
}

int main() {
    zmq::context_t ctx;
    auto thread1 = std::async(std::launch::async, load_subscriber, &ctx, "hello world");
    thread1.wait();
    return 0;
}