//
//  boss.cpp
//  EmployeeManagementSystem
//
//  Created by clockworkSong on 2020/2/25.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include "boss.hpp"

// 构造函数
Boss::Boss(int id, string name, string dep, int level){
    this->m_Id = id;
    this->m_Name = name;
    this->m_Department = dep;
    this->m_Level = level;
}

// 显示个人信息
void Boss::showInfo(){
    cout << "职工编号: " << this->m_Id
        << "\t职工姓名: " << this->m_Name
        << "\t职工部门: " << this->m_Department
        << "\t职工级别: " << this->m_Level
        << "\t职工职责: " << this->description()
        << endl;
}

// 获取岗位名称
string Boss::getDepName(){
    return string("总裁");
}

// 职工职责描述
string Boss::description(){
    return string("完成CEO交给的任务");
}
