cmake_minimum_required(VERSION 3.17)
project(RR_p C)

set(CMAKE_C_STANDARD 99)

add_executable(RR_p driver.c schedulers.c schedulers.h CPU.c CPU.h timer.c timer.h queue.c queue.h task.c task.h)
