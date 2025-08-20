cmake_minimum_required(VERSION 3.31)
project(computer_room)

set(CMAKE_CXX_STANDARD 20)

add_executable(computer_room admin.cpp computer.cpp identity.cpp orderFile.cpp room.cpp student.cpp teacher.cpp)

install(FILES
    admin.txt
    student.txt
    teacher.txt
    computerRoom.txt
    order.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)
