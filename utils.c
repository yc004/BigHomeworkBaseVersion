#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
    FILE* patientFp = fopen("../src/reservationdata.txt", "r");
    readPatient(patientFp, &res_list, doctor_list);

    printf("\033[32m\033[1m初始化完成\n");
    printf("\033[0m-------------------------------------------------\n");
}

void printPatientList() {
    printf("-----------------------------------------------\n");
    const resList* temp = res_list;
    printf("预约编码\t姓名\t电话\t\t日期\t\t科室\t下设科室\t就诊类型\t医保\t医师\t预约状态\n");
    while (temp != NULL) {
        reservation res = temp->data;
        printf("%s\t%s\t%s\t%d/%d/%d\t%s\t%s\t%s\t\t%s\t%s\t%s\n", res.number, res.name, res.phone,
               res.intend_date.year,
               res.intend_date.month,
               res.intend_date.day, mainDepartmentC[res.doctor.department.main],
               getSubDepartment(res.doctor.department), visit_t_c[res.visitType], ensurance[res.isEnsurance],
               res.doctor.name, has_reservation[res.hasRes]);
        temp = temp->next;
    }
    printf("-----------------------------------------------\n");
}

// 用于获取链表长度

static int getLength(const void* list, const int type) {
    int length = 0;
    if (type == 0) {
        const Dlist* temp = list;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
    }
    else if (type == 1) {
        const resList* temp = list;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
    }
    return length;
}

static void sort(void* list, const int type, int (*compare)(void* a_p, void* b_p)) {
    // 如果链表为空，直接返回
    if (list == NULL) {
        return;
    }

    // const int length = getLength(list, type);

    // 当传入的链表为医生链表时
    if (type == 0) {
        int swapped;
        const Dlist* lptr = NULL;

        do {
            swapped = 0;
            Dlist* ptr1 = list;

            while (ptr1->next != lptr) {
                if (compare(ptr1, ptr1->next)) {
                    // 交换节点数据
                    const Doctor temp = ptr1->doctor;
                    ptr1->doctor = ptr1->next->doctor;
                    ptr1->next->doctor = temp;
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        }
        while (swapped);
    }
    // 当传入的链表为患者链表时
    else if (type == 1) {
        int swapped;
        const resList* lptr = NULL;

        do {
            swapped = 0;
            resList* ptr1 = list;

            while (ptr1->next != lptr) {
                if (compare(ptr1, ptr1->next)) {
                    // 交换节点数据
                    const reservation temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        }
        while (swapped);
    }
}


int printSliceMenu(int type) {
    printf("-----------------------------------------------\n");
    char options[][MAX_STRING_LENGTH] = {
        "请选择列表的排序方式：",
        "1.按编号",
        "2.按姓名",
        "3.按可预约人数"
    };

    for (int i = 0; i < 4; ++i) {
        printf("%s", options[i]);
        printf("\n");
    }


    printf("-----------------------------------------------\n");
    char ch = getch();
    return 0;
}


// 打印医生信息列表
void printDocList(const int sortType) {
    /*
     * sortTtpe: 用于判断排序依据
     *  初始默认按照编号排序
     *  0 代表按照姓名排序
     *  1 代表按照编号排序
     */

    Dlist* temp = doctor_list;
    printf("-----------------------------------------------\n");
    printf("编号\t姓名\t性别\t科室\t下设科室\t职称\t\t挂号费\t可预约人数\n");
    if (sortType == 1) {
        sort(temp, 0, compareByDocId);
    }
    else if (sortType == 0) {
        sort(temp, 1, compareByDocName);
    }
    while (temp != NULL) {
        Doctor doctor = temp->doctor;
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n", doctor.id, doctor.name, doctor.gender,
               mainDepartmentC[doctor.department.main],
               getSubDepartment(doctor.department), titleC[doctor.title], doctor.fee, doctor.limit);
        temp = temp->next;
    }
    printf("-----------------------------------------------\n");
}
