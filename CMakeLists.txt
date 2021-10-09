cmake_minimum_required(VERSION 3.20)
project(Networks)

set(CMAKE_CXX_STANDARD 14)

add_executable(Networks main.cpp Client.cpp Client.h Node.cpp Node.h Server.cpp Server.h Actuator.cpp Actuator.h Sender.cpp Sender.h Payload.cpp Payload.h Header.cpp Header.h Receiver.cpp Receiver.h Broker.cpp Broker.h Database.cpp Database.h)
