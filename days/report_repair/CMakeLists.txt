project(report_repair)

include_directories(src)

add_executable(report_repair
        src/rr.cpp)

target_link_libraries(report_repair
        get_cookie
        ${CURL_LIBRARIES})

# add the binary tree so that the codes can see and use the header files
target_include_directories(report_repair PUBLIC
        "${PROJECT_BINARY_DIR}"
        get_cookie
        )
