cmake_minimum_required(VERSION 3.5)
project(tema1)

#setam standardul C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#adaugam directorul src
add_subdirectory(src)

#definim fisierele sursa pentru executabil
set(MY_FILES main.cpp)

#includem directorul de headere
include_directories(include)

#cream executabilul
add_executable(${PROJECT_NAME} ${MY_FILES})

#legam biblioteca noastra locala
target_link_libraries(${PROJECT_NAME} PRIVATE mymusic)