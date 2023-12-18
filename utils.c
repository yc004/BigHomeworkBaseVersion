#include <stdio.h>
#include <stdlib.h>
#include "doctor.h"
#include "reservation.h"

Dlist* doctor_list = NULL;
resList* res_list = NULL;


// 初始化系统
void init() {
    // 用于解决输出乱码问题
    system("chcp 65001");

    printf("\033[44m开始进行系统初始化...\n");

    // 读取医生信息
    FILE* doctorFp = fopen("../src/doctordata.txt", "r");
    readDoctor(doctorFp, &doctor_list);

    // 读取患者预约信息
    FILE* patientFp = fopen("reservationdata.txt", "r");
    readPatient(patientFp, &res_list);

    printf("\033[32m\033[1m初始化完成\n");
    printf("\033[0m-------------------------------------------------\n");
}

// 打印医生信息列表
void printDocList() {
    printf("-----------------------------------------------\n");
    const Dlist* temp = doctor_list;
    printf("编号\t姓名\t性别\t科室\t下设科室\t职称\t\t挂号费\t可预约人数\n");
    while (temp != NULL) {
        Doctor doctor = temp->doctor;
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n", doctor.id, doctor.name, doctor.gender,
               mainDepartmentC[doctor.department.main],
               getSubDepartment(doctor.department), titleC[doctor.title], doctor.fee, doctor.limit);
        temp = temp->next;
    }
    printf("-----------------------------------------------\n");
}
