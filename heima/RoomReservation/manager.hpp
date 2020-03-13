//
//  manager.hpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef manager_hpp
#define manager_hpp

#include <iostream>
#include <fstream>
#include <vector>
//#include <algorithm>
#include "identity.hpp"
#include "teacher.hpp"
#include "student.hpp"
#include "globalFile.h"

using namespace std;

// 管理员类设计
class Manager:public Identity{
public:
    Manager();// 默认构造函数
    Manager(string name, string passwd);// 有参构造
    virtual void operatorMenu();// 菜单界面
    void addAccount();// 添加账号
    void checkAccout();// 查看账号
    void checkMachineRoom();// 查看机房信息
    void clearBookInfo();// 清空预约记录
    void initVector();// 初始化容器
    bool isRepeat(int id, int type);// 是否重复
public:
    vector<Student> vStu;// 学生容器
    vector<Teacher> vTea;// 老师容器
    vector<Machine> vMac;// 机房容器
};

#endif /* manager_hpp */
