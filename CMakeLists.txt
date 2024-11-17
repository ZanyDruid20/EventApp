# CMakeLists.txt

cmake_minimum_required(VERSION 3.26)
project(EventApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(EventApp main.cpp
        Event.h
        Event.cpp
        PriorityQueue.cpp
        PriorityQueue.h
        Order.h
        Scheduler.h
        Scheduler.cpp
        Order.cpp)

# Add a custom target to build the Docker image
add_custom_target(docker-build
        COMMAND docker build -t eventapp .
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Building Docker image for EventApp"
)

# You can add dependencies if needed, for example:
# add_dependencies(EventApp docker-build)
