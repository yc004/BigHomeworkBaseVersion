/*
 * 该系统具有读取、查询、排序、修改、新增、删除、统计、保存、输出等功能。
 */


#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"

enum access {
    doctor,
    administor,
    patient
};

enum access access;


// 打印初始主页面

char printMainMenu(void);

int main() {
    printf("\033[2J");
    init();
    printf("请选择您的操作权限：\n");
    access = getch() - '0';

    while (true) {
        const char action = printMainMenu();
        switch (action) {
            case '1':
                printDocList();
                break;
            case 'q':
                // perror("err\n");
                exit(0);
            default:
                printf("\033[1;31m输入有误， 请重新输入\n");
        }
    }


    return 0;
}

// 用于打印主菜单
char printMainMenu(void) {
    char prompt[][100] = {
        "-----欢迎使用医院预约挂号服务系统-------",
        "1. 打印医生信息列表",
        "2. 排序",
        "3. 输出学生成绩信息",
        "4. 增加新同学",
        "5. 修改学生成绩信息",
        "6. 删除学生",
        "请选择(1-6) 输入q退出系统:"
    };
    for (int i = 0; i < 8; ++i) {
        printf("%s", prompt[i]);
        printf("\n");
    }

    const char ch = getch();
    return ch;
}
