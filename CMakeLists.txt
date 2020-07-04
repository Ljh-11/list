cmake_minimum_required(VERSION 3.16)
project(list)

set(CMAKE_CXX_STANDARD 14)

add_executable(DLinkList DLinkList.cpp)
add_executable(LinkList LinkList.cpp)
add_executable(SqList SqList.cpp)
add_executable(SqStack SqStack.cpp)
add_executable(LinkStack LinkStack.cpp)
add_executable(SqQueue SqQueue.cpp)
add_executable(LinkQueue LinkQueue.cpp)
add_executable(BracketMatching BracketMatching.cpp)