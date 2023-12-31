/*
 * 该系统具有读取、查询、排序、修改、新增、删除、统计、保存、输出等功能。
 */

/*
 * TODO: 目前用户登录功能只实现了输入固定的三个账户和密码登录 且没有对相应的权限做出不同的操作 后续能不能完成就看你的了小伙子！
 */


#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "accessUtils.h"
#include "utils.h"

// 用户权限
enum access access;



char printMainMenu(void);

void wait(void);

int main() {
    init();
    enum access access = getAccess();
    // access = getch() - '0';
    printf("\033[0m");

    while (true) {
        // 清空控制台
        system("cls");

        // 输出主菜单 获取相应的结果
        const char action = printMainMenu();
        printf("%c\n", action);

        // 对不同的结果匹配相应的行为
        switch (action) {
            case '1':
                printDocList();
                wait();
                break;
            case '2':
                printPatientList();
                wait();
                break;
            case 'q': // 键入 q 退出系统
                // perror("err\n");
                return 0;
            default:
                // printf("输入有误， 请重新输入\n");
                printf("其他功能正在开发中...\n");
                wait();
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

// 用于在完成输出后等待用户确认 然后按下任意键清空控制台回到主菜单
void wait(void) {
    printf("=============按任意键继续==============\n");
    getch();
}
