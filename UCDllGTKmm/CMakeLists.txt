cmake_minimum_required(VERSION 3.7)
project(UCDllGTKmm)

set(CMAKE_CXX_STANDARD 14)

file(COPY ../icon DESTINATION .)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
    main.cpp
    UCDllGTKMM.h UCDllGTKMM.cpp
    )
target_link_libraries(${PROJECT_NAME}
    ${GTKMM_LIBRARIES}
 #   ${CMAKE_THREAD_LIBS_INIT}
    )
