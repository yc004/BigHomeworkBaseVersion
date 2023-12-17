cmake_minimum_required(VERSION 3.27)
project(BigHomeworkBaseVersion C)

set(CMAKE_C_STANDARD 11)

add_executable(BigHomeworkBaseVersion main.c
        departmentO.h
        doctor.h
        reservation.h
        date.h
        utils.c
        utils.h
        doctor.c
)
