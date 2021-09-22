cmake_minimum_required(VERSION 3.20)
project(Networks)

set(CMAKE_CXX_STANDARD 14)

add_executable(Networks main.cpp Receiver.cpp Receiver.h Node.cpp Node.h Sender.cpp Sender.h)
