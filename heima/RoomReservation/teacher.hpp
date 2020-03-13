//
//  teacher.hpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef teacher_hpp
#define teacher_hpp

#include <iostream>
#include <vector>
#include "bookFile.hpp"
#include "identity.hpp"

using namespace std;

class Teacher:public Identity{
public:
    Teacher();// 默认构造函数
    Teacher(int id, string name, string passwd);// 有参构造
    virtual void operatorMenu();// 菜单界面
    void checkAllBookState();// 查看所有预约状态
    void validBook();// 审核预约
public:
    int m_Id;// 教师编号
};



#endif /* teacher_hpp */
