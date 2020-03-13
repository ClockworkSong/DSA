//
//  manager.hpp
//  EmployeeManagementSystem
//
//  Created by clockworkSong on 2020/2/25.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef manager_hpp
#define manager_hpp

#include <iostream>
#include "worker.hpp"

using namespace std;

class Manager:public Worker{
public:
    Manager(int id, string name, string dept, int level);// 构造函数
    virtual void showInfo();// 显示个人信息
    virtual string getDepName();// 获取岗位名称
    virtual string description();// 职工描述
};

#endif /* manager_hpp */
