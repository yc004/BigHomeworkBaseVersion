//
// Created by daniel on 2023/12/18.
//

#include "reservation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char* name, const char* isEnsurance, const char* state, char* visitType, reservation* reservation) {
    Doctor* docptr = &reservation->doctor;
    connect(name, &docptr, );

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
        reservation->visitType = 2;
    }
    else {
        reservation->visitType = 1;
    }
}

void readPatient(FILE* fp, resList** res_list) {
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
        convert(docName, isEnsurance, state, visitType, &new->data);

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

    fclose(fp);
    *res_list = head;
}
