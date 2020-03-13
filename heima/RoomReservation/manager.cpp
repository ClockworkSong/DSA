//
//  manager.cpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include "manager.hpp"

// 默认构造函数
Manager::Manager(){
    
}
// 有参构造
Manager::Manager(string name, string passwd){
    this->m_Name = name;
    this->m_Passwd = passwd;
    // 初始化容器，获取文件中所有老师和学生信息
    this->initVector();
    // 初始化机房容器信息
    ifstream ifs;
    ifs.open(MACHINE_FILE, ios::in);
    Machine m;
    while (ifs >> m.m_Id && ifs >> m.m_Capacity) {
        vMac.push_back(m);
    }
    ifs.close();
    cout << "机房的数量为：" << vMac.size() << endl;
}
// 初始化容器
void Manager::initVector(){
    this->vStu.clear();
    this->vTea.clear();
    // 读取信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "打开文件失败" << endl;
        return;
    }
    Student st;
    while (ifs >> st.m_Id && ifs >> st.m_Name && ifs >> st.m_Passwd) {
//        cout << "id:" << st.m_Id << "\tname:" << st.m_Name << "\tpasswd:" << st.m_Passwd << endl;
        this->vStu.push_back(st);
    }
    cout << "当前学生的数量：" << vStu.size() << endl;
    ifs.close();
    
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "打开文件失败" << endl;
        return;
    }
    Teacher te;
    while (ifs >> te.m_Id && ifs >> te.m_Name && ifs >> te.m_Passwd) {
//        cout << "id:" << te.m_Id << "\tname:" << te.m_Name << "\tpasswd:" << te.m_Passwd << endl;
        this->vTea.push_back(te);
    }
    cout << "当前教师的数量：" << vTea.size() << endl;
    ifs.close();
}
// 是否重复
bool Manager::isRepeat(int id, int type){
    if(type == 1){
        // 检测学生
        for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++){
            if(id == it->m_Id) return true;
        }
    }
    else{
        // 检测老师
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            if(id == it->m_Id) return true;
        }
    }
    return false;
}
// 菜单界面
void Manager::operatorMenu(){
    cout << "**************************" << endl;
    cout << "******** 1.添加账号 *******" << endl;
    cout << "******** 2.查看账号 *******" << endl;
    cout << "******** 3.查看机房 *******" << endl;
    cout << "******** 4.清空预约 *******" << endl;
    cout << "******** 0.注销登录 *******" << endl;
    cout << "**************************" << endl;
}
// 添加账号
void Manager::addAccount(){
    cout << "请输入添加账号类型：1学生，2老师";
    string fName;// 操作文件名
    string tipInfo;// 提示信息
    string errorTip;// 重复错误提示
    ofstream ofs;
    int select = 0;
    cin >> select;
    
    if(select == 1){
        fName=STUDENT_FILE;
        tipInfo="请输入学号：";
        errorTip = "学号重复";
    }
    else{
        fName=TEACHER_FILE;
        tipInfo="请输入工号：";
        errorTip = "工号重复";
    }
    ofs.open(fName, ios::out | ios::app);// 利用追加方式写文件
    int id;
    string name;
    string passwd;
    cout << tipInfo << endl;
    while (true) {
        cin >> id;
        if(!isRepeat(id, select)){
            break;
        }
        else{
            cout << errorTip << endl;
            cout << "请重新输入：";
        }
    }
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入密码：";
    cin >> passwd;
    // 向文件中添加数据
    ofs << id << " " << name << " " << passwd << " " << endl;
    cout << "添加成功！" << endl;
    // 更新文件信息
    this->initVector();
    ofs.close();
}
// 打印学生信息
void printStudent(Student& s){
    cout << "学号：" << s.m_Id << "\t姓名：" << s.m_Name << "\t密码：" << s.m_Passwd << endl;
}
// 打印老师信息
void printTeacher(Teacher& t){
    cout << "学号：" << t.m_Id << "\t姓名：" << t.m_Name << "\t密码：" << t.m_Passwd << endl;
}
// 查看账号
void Manager::checkAccout(){
    cout << "请选择查看内容：1学生，2老师";
    int select = 0;
    cin >> select;
    
    if(select == 1){
        // 查看学生
        cout << "所有学生信息如下：" << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);// 仿函数printStudent
    }
    else{
        // 查看老师
        cout << "所有老师信息如下：" << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);// 仿函数printStuden
    }
}
// 查看机房信息
void Manager::checkMachineRoom(){
    cout << "机房的信息如下：" << endl;
    for(vector<Machine>::iterator it = vMac.begin(); it != vMac.end(); it++){
        cout << "机房编号："<< it->m_Id << "\t数量：" << it->m_Capacity << endl;
    }
}
// 清空预约记录
void Manager::clearBookInfo(){
    ofstream ofs;
    ofs.open(BOOK_FILE, ios::trunc);
    ofs.close();
    cout << "清空成功！" << endl;
}
