//
// Created by daniel on 2023/12/18.
//

#ifndef ACCESSUTILS_H
#define ACCESSUTILS_H

enum access { admin, doctor, patient };

struct user {
    char username[30];
    char password[30];
};

// 获取用户的操作权限
extern enum access getAccess();




#endif //ACCESSUTILS_H
