project(get_cookie)

include_directories(src)

add_library(get_cookie
        src/google_chrome.cpp get_cookie.h)
target_include_directories(get_cookie PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})