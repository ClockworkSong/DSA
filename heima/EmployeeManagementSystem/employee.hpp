//
//  employee.hpp
//  EmployeeManagementSystem
//
//  Created by clockworkSong on 2020/2/25.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef employee_hpp
#define employee_hpp

#include <iostream>
#include "worker.hpp"

using namespace std;

class Employee:public Worker{
public:
    Employee(int id, string name, string dept, int level);// 构造函数
    virtual void showInfo();// 显示个人信息
    virtual string getDepName();// 获取岗位名称
    virtual string description();// 职工描述
};

#endif /* employee_hpp */
