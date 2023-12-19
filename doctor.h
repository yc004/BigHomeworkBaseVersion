#ifndef DOCTOR_H
#define DOCTOR_H

#include <stdio.h>
#define MAX_STRING_LENGTH 100


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
    char name[MAX_STRING_LENGTH];
    char gender[MAX_STRING_LENGTH];
    Department department;
    enum title title;
    int fee;
    char available[MAX_STRING_LENGTH];
    int limit;
} Doctor;

// 医生数据链表
typedef struct doctorList {
    Doctor doctor;
    struct doctorList* next;
} Dlist;


extern void readDoctor(FILE* fp, Dlist** doctor_list);

extern char* getSubDepartment(Department department);

extern int compareByDocName(void* a_p, void* b_p);

extern int compareByDocId(void* a_p, void* b_p);


#endif //DOCTOR_H
