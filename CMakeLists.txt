cmake_minimum_required(VERSION 3.7)
project(Ucdll)
set(CMAKE_CXX_STANDARD 14)

# Boost.system
find_package(Boost COMPONENTS thread system filesystem REQUIRED ) #whatever libs you need
include_directories(${Boost_INCLUDE_DIRS})

# Threads
find_package(Threads)

add_executable(${PROJECT_NAME}
    main.cpp

    UCDll.h UCDll.cpp
    )
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    )
