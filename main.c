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

int access;


// 打印初始主页面

char printMainMenu(void);

int main() {
    init();
    scanf("请选择您的操作权限：\n", &access);

    while (true) {
        char action = printMainMenu();
        switch (action) {
            case '1':
                printDocList();
                break;
            default:
                printf("err");
                exit(0);

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
        "0. 退出",
        "请选择(0-6):"
    };
    for (int i = 0; i < 9; ++i) {
        printf("%s", prompt[i]);
        printf("\n");
    }

    const char ch = getch();

    return ch;
}
