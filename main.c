/*
 * 该系统具有读取、查询、排序、修改、新增、删除、统计、保存、输出等功能。
 */


#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "accessUtils.h"
#include "utils.h"


enum access access;


// 打印初始主页面

char printMainMenu(void);

void wait(void);

int main() {
    init();
    enum access access = getAccess();
    // access = getch() - '0';

    while (true) {
        // 清空控制台
        system("cls");
        const char action = printMainMenu();
        switch (action) {
            case '1':
                printDocList();
                wait();
                break;
            case '2':
                break;
            case 'q': // 键入 q 退出系统
                // perror("err\n");
                return 0;
            default:
                printf("输入有误， 请重新输入\n");
        }
    }
}

// 用于打印主菜单

char printMainMenu(void) {
    char prompt[][100] = {
        "-----欢迎使用医院预约挂号服务系统-------",
        "1. 输出医生信息列表",
        "2. 输出患者预约信息",
        "3. 添加医生信息",
        "4. 添加患者预约信息",
        "5. 修改医生信息",
        "6. 修改患者预约信息",
        "7. 查找医生",
        "8. 查找患者",
        "请选择(1-8) 输入q退出系统:"
    };
    for (int i = 0; i < 10; ++i) {
        printf("%s", prompt[i]);
        printf("\n");
    }

    const char ch = getch();
    return ch;
}

void wait(void) {
    printf("==========按任意继键续==============\n");
    getch();
}
