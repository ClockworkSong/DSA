//
//  main.cpp
//  EmployeeManagementSystem
//
//  Created by clockworkSong on 2020/2/25.
//  Copyright © 2020 clockworkSong. All rights reserved.
//
/*
 管理类：
 1.与用户的沟通菜单界面
 2.对职工增删改查的操作
 3.与文件的读写交互
 职工类：
 1.职工分为普通员工、经理和老板
 2.将三种职工抽象到一个类中，利用多态管理不同职工种类
 3.职工的属性为编号、姓名和部门
 4.职工的行为有岗位职责信息描述、岗位名称
 */

#include <iostream>
#include "workManager.hpp"

using namespace std;

void test01(){
    Worker *wk = NULL;
    wk = new Employee(10, "sxd", "Arm plateform", 1);
    wk->showInfo();
    delete wk;
    
    wk = new Manager(11, "yxb", "Arm plateform", 2);
    wk->showInfo();
    delete wk;
    
    wk = new Boss(12, "sl", "Arm plateform", 3);
    wk->showInfo();
    delete wk;
}

int main(int argc, const char * argv[]) {
    
    WorkManager ws;// 实例化管理者对象
    int opt;// 用来存储用户输入选项
    while (true) {
        ws.showMenu();
        cout << "请输入您的选择: ";
        cin >> opt;
        switch (opt) {
            case 1://添加
                ws.addEmployee();
                break;
            case 2://显示
                ws.showEmployee();
                break;
            case 3://删除
                ws.deleteEmployee();
                break;
            case 4://修改
                ws.modifyEmployee();
                break;
            case 5://查找
                ws.SelectEmployee();
                break;
            case 6://排序
                ws.sortEmployee();
                break;
            case 7://清空
                ws.destroyEmployee();
                break;
            case 0://退出
                ws.exitSystem();
                break;
            default:
                break;
        }
    }
//    test01();
    return 0;
}
