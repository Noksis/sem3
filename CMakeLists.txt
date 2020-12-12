cmake_minimum_required(VERSION 3.17)
project(sem3)

set(CMAKE_CXX_STANDARD 11)

add_executable(sem3 MyRuns.c server.c client.c count.c Boat.c symlinks.c)