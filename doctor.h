#ifndef DOCTOR_H
#define DOCTOR_H
#include <stdio.h>
#include <string.h>

#include "departmentO.h"

// 知名专家、主任医师、副主任医师、主治医师和医师
enum title {
    physicians,
    staff,
    cheif,
    archiater,
    famous
};

const static char titleC[][20] = {"医师", "主治医师", "副主任医师", "主任医师", "知名专家"};

// 医生信息
typedef struct doctor {
    int id;
    char name[5];
    char gender;
    Department department;
    enum title title;
    int fee;
    char available[14];
    int limit;
} Doctor;

// 医生数据链表
typedef struct doctorList {
    Doctor doctor;
    struct doctorList* next;
} Dlist;

// 将字符串类型的门诊科室转换为对应的枚举 将职称的字符串转换为枚举
inline void convert(const char* main, const char* sub, const char* title, Doctor* doctor);

inline void readDoctor(FILE* fp, Dlist** doctor_list);

#endif //DOCTOR_H
