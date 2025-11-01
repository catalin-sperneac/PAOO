cmake_minimum_required(VERSION 3.5)
project(myvector)

#definim fisierele bibliotecii
set(SRC_FILES MyVector.cpp)

#cream o biblioteca statica
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

#specificam unde sunt headerele
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)