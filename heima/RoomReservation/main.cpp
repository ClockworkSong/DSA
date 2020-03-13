//
//  main.cpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
// 机房预约系统

#include <iostream>
#include <fstream>
#include "identity.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "manager.hpp"
#include "globalFile.h"

using namespace std;


void returnContinue();// 自定义回车继续

// 功能菜单
void showMenu(){
    cout << "************************" << endl;
    cout << "*** 欢迎使用机房预约系统 ***" << endl;
    cout << "******** 1.学  生 *******" << endl;
    cout << "******** 2.老  师 *******" << endl;
    cout << "******** 3.管  理 *******" << endl;
    cout << "******** 0.退  出 *******" << endl;
    cout << "************************" << endl;
}
// 进入老师子菜单界面
void TeacherMenu(Identity* teacher){
    while (true) {
        // 调用老师子菜单
        teacher->operatorMenu();
        // 将父类指针转为子类指针，调用子类里其他接口
        Teacher* tea = (Teacher*)teacher;
        int select = 0;
        cout << "请输入您的选择: ";
        cin >> select;// 接收用户选择
        if(select == 1){// 查看预约
            tea->checkAllBookState();
        }
        else if(select == 2){// 审核预约
            tea->validBook();
        }
        else{// 注销登录
            delete teacher;
            cout << "注销成功！" << endl;
            returnContinue();
            break;
        }
    }
}
// 进入学生子菜单界面
void studentMenu(Identity* student){
    while (true) {
        // 调用学生子菜单
        student->operatorMenu();
        // 将父类指针转为子类指针，调用子类里其他接口
        Student* stu = (Student*)student;
        int select = 0;
        cout << "请输入您的选择: ";
        cin >> select;// 接收用户选择
        if(select == 1){// 申请预约
            stu->applyBook();
        }
        else if(select == 2){// 查看自身预约
            stu->checkSelfBookState();
        }
        else if(select == 3){// 查看所有人预约
            stu->checkAllBookState();
        }
        else if(select == 4){// 取消预约
            stu->cancelBook();
        }
        else{// 注销登录
            delete student;
            cout << "注销成功！" << endl;
            returnContinue();
            break;
        }
    }
}

// 进入管理员子菜单界面
void managerMenu(Identity* manager){
    while (true) {
        // 调用管理员子菜单
        manager->operatorMenu();
        // 将父类指针转为子类指针，调用子类里其他接口
        Manager* mgr = (Manager*)manager;
        int select = 0;
        cout << "请输入您的选择: ";
        cin >> select;// 接收用户选择
        if(select == 1){// 添加账号
            mgr->addAccount();
        }
        else if(select == 2){// 查看账号
            mgr->checkAccout();
        }
        else if(select == 3){// 查看机房
            mgr->checkMachineRoom();
        }
        else if(select == 4){// 清空预约
            mgr->clearBookInfo();
        }
        else{
            delete manager;// 销毁对象
            cout << "注销成功！" << endl;
            returnContinue();
            break;
        }
    }
}

// 自定义回车继续
void returnContinue(){
    cout << "请输入回车继续..." << endl;
    cin.get();
    getchar();
}

// 退出系统
void exitSystem(){
    cout << "欢迎下次使用！" << endl;
    returnContinue();
    exit(0);
}

// 登录功能
void LoginIn(string fileName, int idType){
    Identity* person = NULL;// 父类指针指向子类对象
    ifstream ifs;
    ifs.open(fileName, ios::in);
    // 判断文件是否存在
    if(!ifs.is_open()){
        cout << "文件不存在！" << endl;
        return;
    }
    // 准备接收用户信息
    int id = 0;
    string name;
    string passwd;
    // 判断身份
    if(idType == 1){
        cout << "请输入学号：";
        cin >> id;
    }
    else if(idType == 2){
        cout << "请输入工号：";
        cin >> id;
    }
    cout << "请输入用户名：";
    
    cin >> name;
    cout << "请输入密码：";
    cin >> passwd;
    
    if(idType == 1){
        // 学生身份验证
        int fId;// 从文件中读取的id号
        string fName;// 从文件中获取的姓名
        string fPasswd;// 从文件中获取的密码
        while (ifs >> fId && ifs >> fName && ifs >> fPasswd) {
//            cout <<"学号：" << fId <<"\t姓名："<<  fName <<"\t密码："<< fPasswd << endl;
            // 与用户输入信息做对比
            if(fId == id && fName == name && fPasswd == passwd){
                cout << "学生验证登录成功！" << endl;
                returnContinue();
                person = new Student(id, name, passwd);
                // 进入学生身份子菜单
                studentMenu(person);
                return;
            }
        }
    }
    else if(idType == 2){
        // 教师身份验证
        int fId;// 从文件中读取的id号
        string fName;// 从文件中获取的姓名
        string fPasswd;// 从文件中获取的密码
        while (ifs >> fId && ifs >> fName && ifs >> fPasswd) {
            // 与用户输入信息做对比
            if(fId == id && fName == name && fPasswd == passwd){
                cout << "教师验证登录成功！" << endl;
                returnContinue();
                person = new Teacher(id, name, passwd);
                // 进入教师身份子菜单
                TeacherMenu(person);
                return;
            }
        }
    }
    else if(idType == 3){
        // 管理身份验证
        string fName;// 从文件中获取的姓名
        string fPasswd;// 从文件中获取的密码
        while (ifs >> fName && ifs >> fPasswd) {
            // 与用户输入信息做对比
            if(fName == name && fPasswd == passwd){
                cout << "管理验证登录成功！" << endl;
                returnContinue();
                person = new Manager(name, passwd);
                // 进入管理身份子菜单
                managerMenu(person);
                return;
            }
        }
    }
    cout << "验证登录失败！" << endl;
    returnContinue();
}

int main(int argc, const char * argv[]) {
    ifstream ifs;
    ifs.open(ADMIN_FILE, ios::in);
    if(!ifs.is_open()){// 如果文件不存在则创建文件
        ofstream ofs;
        ofs.open(ADMIN_FILE, ios::out);
        ofs << "admin " << "admin" << endl;
        ofs.close();
    }
    ifs.close();
    ifs.open(MACHINE_FILE, ios::in);
    if(!ifs.is_open()){// 如果文件不存在则创建文件
        ofstream ofs;
        ofs.open(MACHINE_FILE, ios::out);
        ofs << "1 " << "20" << endl;
        ofs << "2 " << "50" << endl;
        ofs << "3 " << "100" << endl;
        ofs.close();
    }
    ifs.close();
    int select = 0;
    while (true) {
        showMenu();
        cout << "请输入您的选择: ";
        cin >> select;
        switch (select) {
            case 1:// 学生身份
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2:// 老师身份
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3:// 管理员身份
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0:// 退出系统
                exitSystem();
                break;
            default:
                break;
        }
    }
    return 0;
}
