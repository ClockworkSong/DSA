//
//  workManager.hpp
//  EmployeeManagementSystem
//
//  Created by clockworkSong on 2020/2/25.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef workManager_hpp
#define workManager_hpp

#include <iostream>
#include <fstream>
#include "worker.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"

#define FILENAME "info.txt"

using namespace std;

class WorkManager{
public:
    WorkManager();// 构造函数
    void showMenu();// 显示菜单界面
    void exitSystem();// 退出系统
    void returnContinue();// 自定义回车继续
    void addEmployee();// 添加职工
    void showEmployee();// 显示职工
    int isExist(int id);// 判断职工是否存在
    void deleteEmployee();// 删除职工
    void modifyEmployee();// 修改职工信息
    void SelectEmployee();// 查找职工信息
    void sortEmployee();// 排序职工信息
    void destroyEmployee();// 清空职工信息
    void saveInformation();// 保存文件
    int getEmployeeNumber();// 统计文件中人数
    void initEmployee();// 初始化员工
    ~WorkManager();// 析构函数
public:
    int m_Number;// 记录职工人数
    Worker** m_pArray;// 职工数组指针
    bool m_EmptyFlag;// 判断文件是否为空标志位
};

#endif /* workManager_hpp */
