#ifndef DOCTOR_H
#define DOCTOR_H
#include <string.h>

#include "departmentO.h"

enum title {};
// 医生信息
typedef struct doctor {
    int id;
    char name[5];
    char gender;
    Department department;
    int title;
    int fee;
    char available[14];
    int limit;
} Doctor;

// 医生数据链表
typedef struct doctorList {
    Doctor doctor;
    struct doctorList* next;
} Dlist;

// 用与存储数据
extern Dlist* doctor_list = NULL;

// 将字符串类型的门诊科室转换为对应的枚举
inline void convert(const char* main, const char* sub, Doctor* doctor) {
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
}

inline void readDoctor(FILE* fp) {
    if (fp == NULL) {
        printf("Error occured when reading the doctordata!");
        exit(0);
    }

    Dlist *head = NULL, *tail = NULL;
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
        convert(main, sub, &new->doctor);
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
    doctor_list = head;
}



#endif //DOCTOR_H
