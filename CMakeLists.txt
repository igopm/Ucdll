cmake_minimum_required(VERSION 3.7)
project(Ucdll)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}
    main.cpp

    UCDll.h UCDll.cpp
    )
