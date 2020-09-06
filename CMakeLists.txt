cmake_minimum_required(VERSION 3.2)

project(zmq-test)

find_package(cppzmq)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(rep-server rep-server.cpp)
target_link_libraries(rep-server cppzmq)
add_executable(req-client req-client.cpp)
target_link_libraries(req-client cppzmq)


add_executable(pub-server pub-server.cpp)
target_link_libraries(pub-server cppzmq)



add_executable(sub-server sub-server.cpp)
target_link_libraries(sub-server cppzmq)