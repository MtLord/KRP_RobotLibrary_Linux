set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")
set(PROJECT_NAME app)
find_package(Boost 1.65.1 REQUIRED COMPONENTS date_time system)
find_package(Threads REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/libraries/inc)
add_executable(${PROJECT_NAME} main.cpp ) 
target_link_libraries(${PROJECT_NAME} interim)#ロボットライブラリのリンク
target_link_libraries(${PROJECT_NAME} Boost::system ${CMAKE_THREAD_LIBS_INIT} Threads::Threads)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} rt)
