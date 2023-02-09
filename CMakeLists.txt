cmake_minimum_required(VERSION 3.24)
project(QuantitativeFinance)

set(CMAKE_CXX_STANDARD 23)

add_executable(QuantitativeFinance main.cpp asianoption.cpp asianoption.h pathgeneration.h payoff.cpp)
