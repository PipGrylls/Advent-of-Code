cmake_minimum_required(VERSION 3.10)

project(get_cookie VERSION 1.0)

include_directories(src)

add_executable(get_cookie
       src/google_chrome.cpp)