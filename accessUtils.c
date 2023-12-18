//
// Created by daniel on 2023/12/18.
//

#include "accessUtils.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "conio.h"

char username[30];
char password[30];

const struct user adminU = {"admin", "123456"};
const struct user doctorU = {"doctor", "654321"};
const struct user patientU = {"patient", "56789"};

// TODO: 让用户输入账户和密码 根据不同的账户返回不同的权限
enum access getAccess() {
    while (true) {
        printf("请输入您的用户名：\n");
        fgets(username, 30, stdin);
        printf("请输入您的密码：\n");
        int i = 0;

        // 读取密码
        while (true) {
            const char ch = getch();

            if (ch == '\r' || ch == '\n') {
                // 捕获回车键
                password[i] = '\0'; // 在密码末尾添加 null 终止符
                break;
            }
            else if (ch == 8 && i > 0) {
                // 捕获退格键
                printf("\b \b"); // 删除前一个字符的星号
                i--;
            }
            else if (i < 30 - 1) {
                password[i] = ch;
                printf("*"); // 用星号代替实际输入
                i++;
            }
        }

        if (strcmp(username, adminU.username) == 0) {
            if (strcmp(password, adminU.password) == 0) {
                printf("登录成功 您现在的身份是管理员\n");
                return admin;
            }
            printf("密码错误 请重试\n");
        }
        else if (strcmp(username, doctorU.username) == 0) {
            if (strcmp(password, doctorU.password) == 0) {
                printf("登录成功 您现在的身份是医生\n");
                return doctor;
            }
            printf("密码错误 请重试\n");
        }
        else if (strcmp(username, patientU.username) == 0) {
            if (strcmp(password, patientU.password) == 0) {
                printf("登录成功 您现在的身份是患者\n");
                return patient;
            }
            printf("密码错误 请重试\n");
        }
    }
}
