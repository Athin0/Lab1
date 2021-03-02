cmake_minimum_required(VERSION 3.17)
project(depo2 C)

set(CMAKE_C_STANDARD 99)

add_executable(depo2 main.c proto.c proto.h functions_int.c functions_int.h functions_float.c functions_float.h meny.c meny.h)