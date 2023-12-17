#include <stdio.h>
#include <stdlib.h>
#include "doctor.h"
#include "reservation.h"

Dlist* doctor_list = NULL;


// 初始化系统
extern void init() {
    // 用于解决输出乱码问题
    system("chcp 65001");

    // 读取医生信息
    FILE* doctorFp = fopen("doctordata.txt", "r");
    readDoctor(doctorFp, &doctor_list);

    // 读取患者预约信息
    FILE* patientFp = fopen("reservationdata.txt", "r");
    readPatient(patientFp);
}

// 打印医生信息列表
extern void printDocList() {
    const Dlist* temp = doctor_list;
    while (temp != NULL) {
        Doctor doctor = temp->doctor;
        printf("%5d, %5s %c\n", doctor.id, doctor.name, doctor.gender);
        temp = temp->next;
    }
    printf("--------------------");
}
