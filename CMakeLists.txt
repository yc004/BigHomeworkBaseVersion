cmake_minimum_required(VERSION 3.27)
project(BigHomeworkBaseVersion C)

set(CMAKE_C_STANDARD 11)

add_executable(BigHomeworkBaseVersion main.c
        departmentO.h
        departmentO.c
        doctor.h
        doctor.c
        reservation.h
        reservation.c
        utils.h
        utils.c
        accessUtils.h
        accessUtils.c
        date.h
)
