//
//  student.hpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef student_hpp
#define student_hpp

#include <iostream>
#include <vector>
#include <fstream>
#include "identity.hpp"
#include "globalFile.h"
#include "bookFile.hpp"

using namespace std;

class Student:public Identity{
public:
    Student();// 默认构造函数
    Student(int id, string name, string passwd);// 有参构造
    virtual void operatorMenu();//  菜单界面
    void applyBook();// 申请预约
    void checkSelfBookState();// 查看自身预约状态
    void checkAllBookState();// 查看所有预约状态
    void cancelBook();// 取消预约
public:
    int m_Id;// 学生学号
    vector<Machine> vMac;// 机房容量
};

#endif /* student_hpp */
