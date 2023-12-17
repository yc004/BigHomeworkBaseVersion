#ifndef UTILS_H
#define UTILS_H

#include "doctor.h"

// 初始化系统
inline void init() {
    // 用于解决输出乱码问题
    system("chcp 65001");

    // 读取医生信息
    FILE* doctorFp = fopen("doctordata.txt", "r");
    readDoctor(doctorFp);

    // 读取患者预约信息
    const FILE* patientFp = fopen("reservationdata.txt", "r");
    readPatient();
}

// 打印医生信息列表
inline void printDocList() {
    const Dlist* temp = doctor_list;
    while (temp != NULL) {
        printf("%5d, %5s %c %5s %10s %10s %5d %15s %5d\n");
        temp = temp->next;
    }
}


#endif //UTILS_H
