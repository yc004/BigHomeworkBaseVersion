//
// Created by daniel on 2023/12/17.
//

#include "doctor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


inline void convert(const char* main, const char* sub, const char* title, Doctor* doctor) {
    for (int i = 0; i < sizeof(enum mainDepartment); ++i) {
        if (strcmp(main, mainDepartmentC[i]) == 0) {
            doctor->department.main = i;
            switch (i) {
                case 0:
                    for (int j = 0; j < sizeof(enum IMD); ++j) {
                        if (strcmp(sub, IMDC[j]) == 0) {
                            doctor->department.sub.imd = j;
                        }
                    }
                    break;
                case 1:
                    for (int j = 0; j < sizeof(enum SD); ++j) {
                        if (strcmp(sub, SDC[j]) == 0) {
                            doctor->department.sub.sd = j;
                        }
                    }
                    break;

                case 2:
                    for (int j = 0; j < sizeof(enum PD); ++j) {
                        if (strcmp(sub, PDC[j]) == 0) {
                            doctor->department.sub.pd = j;
                        }
                    }
                    break;

                case 3:
                    for (int j = 0; j < sizeof(enum ED); ++j) {
                        if (strcmp(sub, EDC[j]) == 0) {
                            doctor->department.sub.ed = j;
                        }
                    }
                    break;
                default:
                    printf("Read error");
                    exit(0);
            }
        }
    }

    for (int i = 0; i < sizeof(enum title); ++i) {
        if (strcmp(title, titleC[i])) {
            doctor->title = i;
        }
    }
}

inline void readDoctor(FILE* fp, Dlist** doctor_list) {
    if (fp == NULL) {
        printf("医生信息文件打开失败\n");
        exit(-1);
    }

    Dlist *tail = NULL, *head = NULL;
    int id;
    char name[5];
    char gender;
    char main[10];
    char sub[10];
    char title[20];
    int fee;
    char available[14];
    int limit;
    while (fscanf(fp, "%d %s %c %s %s %s %d %s %d", &id, name, &gender, main, sub, title, &fee, available,
                  &limit) != EOF
    ) {
        Dlist* new = malloc(sizeof(Dlist));
        new->doctor.id = id;
        new->doctor.gender = gender;
        new->doctor.fee = fee;
        new->doctor.limit = limit;
        printf("%s", name);
        convert(main, sub, title, &new->doctor);
        if (head == NULL) {
            head = tail = new;
        }
        else {
            if (tail != NULL) {
                tail->next = new;
                tail = new;
            }
            else {
                printf("内存分配失败");
                exit(0);
            }
        }
    }
    printf("医生信息读取完成");
    // 关闭文件
    fclose(fp);
    // 让 doctor_list 指向链表的头
    *doctor_list = head;
}