//
//  boss.hpp
//  EmployeeManagementSystem
//
//  Created by clockworkSong on 2020/2/25.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef boss_hpp
#define boss_hpp

#include <iostream>
#include "worker.hpp"

using namespace std;

class Boss:public Worker{
public:
    Boss(int id, string name, string dept, int level);// 构造函数
    virtual void showInfo();// 显示个人信息
    virtual string getDepName();// 获取岗位名称
    virtual string description();// 职工描述
};

#endif /* boss_hpp */
