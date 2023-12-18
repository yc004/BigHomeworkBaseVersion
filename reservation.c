//
// Created by daniel on 2023/12/18.
//

#include "reservation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void convert(const char* name, const char* isEnsurance, const char* state, const char* visitType,
                    reservation* reservation,
                    const Dlist* doc_list) {
    // connect(name, &docptr, );

    if (strcmp(isEnsurance, "是") == 0) {
        reservation->isEnsurance = 1;
    }
    else {
        reservation->isEnsurance = 0;
    }

    if (strcmp(state, "已预约") == 0) {
        reservation->hasRes = 1;
    }
    else {
        reservation->hasRes = 0;
    }

    if (strcmp(visitType, "初诊") == 0) {
        reservation->visitType = 0;
    }
    else {
        reservation->visitType = 1;
    }

    const Dlist* tmp = doc_list;
    while (tmp != NULL) {
        if (strcmp(name, tmp->doctor.name) == 0) {
            reservation->doctor = tmp->doctor;
            return;
        }

        tmp = tmp->next;
    }
}

void readPatient(FILE* fp, resList** res_list, Dlist* doc_list) {
    resList *head = NULL, *tail = NULL;
    int number;
    char name[20];
    char phone[12];
    int year, month, day;
    char main[20], sub[20];
    char visitType[20];
    char isEnsurance[20];
    char docName[20];
    char state[20];


    while (fscanf(fp, "%d %s %s %d/%d/%d %s %s %s %s %s %s", &number, name, phone, &year, &month, &day, main, sub,
                  visitType, isEnsurance, docName, state) != EOF) {
        resList* new = malloc(sizeof(resList));
        new->data.number = number;
        new->data.intend_date.year = year;
        new->data.intend_date.month = month;
        new->data.intend_date.day = day;
        strcpy(new->data.name, name);
        strcpy(new->data.phone, phone);
        convert(docName, isEnsurance, state, visitType, &new->data, doc_list);

        if (head == NULL) {
            head = tail = new;
        }
        else {
            if (tail != NULL) {
                tail->next = new;
                tail = new;
            }
            else {
                printf("内存分配失败\n");
                exit(0);
            }
        }
        new->next = NULL;
    }
    if (tail != NULL) {
        tail->next = NULL;
    }

    printf("患者预约信息初始化完成\n");
    fclose(fp);
    *res_list = head;
}
