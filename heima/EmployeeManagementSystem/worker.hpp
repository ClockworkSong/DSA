//
//  worker.hpp
//  EmployeeManagementSystem
//
//  Created by clockworkSong on 2020/2/25.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef worker_hpp
#define worker_hpp

#include <iostream>

using namespace std;

// 职工抽象类
class Worker{
public:
    virtual void showInfo() = 0;// 显示个人信息
    virtual string getDepName() = 0;// 获取岗位名称
    virtual string description() = 0;// 描述职能
    int m_Id;// 编号
    string m_Name;// 姓名
    string m_Department;// 部门
    int m_Level;// 级别
    virtual ~Worker(){}
};

#endif /* worker_hpp */
