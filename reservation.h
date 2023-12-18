/*
  * 预约信息文件存储了预约就医的患者信息，每条信息至少包括
 * 记录编号（记录编号不可重复）
 * 患者姓名
 * 患者电话
 * 拟就诊日期
 * 要预约的大类科室和门诊科室
 * 初诊/复诊
 * 是否医保
 * 医生姓名
 * 当前状态（分为两类：已取消、已预约）
 */
#ifndef PATIENT_H
#define PATIENT_H


#include <stdio.h>

#include "date.h"
#include "departmentO.h"
#include "doctor.h"


// 患者预约信息
typedef struct Res {
    int number;
    char name[5];
    char phone[12];
    date intend_date;
    int visitType;
    int isEnsurance;
    Doctor doctor;
    int hasRes;
} reservation;

//  患者预约信息链表
typedef struct listNode {
    reservation data;
    struct listNode* next;
} resList;


extern void readPatient(FILE* fp, resList** res_list);

#endif //PATIENT_H
