//
//  student.cpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include "student.hpp"

// 默认构造函数
Student::Student(){
    
}
// 有参构造
Student::Student(int id, string name, string passwd){
    this->m_Id = id;
    this->m_Name = name;
    this->m_Passwd = passwd;
    // 初始化机房信息
    ifstream ifs;
    ifs.open(MACHINE_FILE, ios::in);
    Machine m;
    while (ifs >> m.m_Id && ifs >> m.m_Capacity) {
        vMac.push_back(m);
    }
    ifs.close();
    cout << "机房的数量为：" << vMac.size() << endl;
}
// 菜单界面
void Student::operatorMenu(){
    cout << "**************************" << endl;
    cout << "******** 1.申请预约 *******" << endl;
    cout << "******** 2.查看我的预约 ****" << endl;
    cout << "******** 3.查看所有预约 ****" << endl;
    cout << "******** 4.取消预约 *******" << endl;
    cout << "******** 0.注销登录 *******" << endl;
    cout << "**************************" << endl;
}
// 申请预约
void Student::applyBook(){
    cout << "机房开放时间为周一至周五！" << endl;
    cout << "请输入申请预约时间：1~5代表周一~周五" << endl;
    int date = 0;// 日期
    int interval = 0;// 时间段
    int room = 0;// 机房编号
    while(true){
        cin >> date;
        if(date >= 1 && date <= 5) break;
        cout << "输入有误，请重新输入！" << endl;
    }
    cout << "请输入申请预约时间段：1上午，2下午" << endl;
    while(true){
        cin >> interval;
        if(interval == 1 || interval == 2) break;
        cout << "输入有误，请重新输入！" << endl;
    }
    cout << "请选择机房：" << endl;
    for(int i = 0; i < vMac.size(); i ++){
        cout << vMac[i].m_Id << "号机房容量为：" << vMac[i].m_Capacity << endl;
    }
    while(true){
         cin >> room;
         if(room >= 1 && room <= 3) break;
         cout << "输入有误，请重新输入！" << endl;
    }
    cout << "预约成功，审核中！" << endl;
    ofstream ofs;
    ofs.open(BOOK_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "state:" << 1 << endl;
    ofs.close();
}
// 查看自身预约状态
void Student::checkSelfBookState(){
    BookFile bf;
    if(bf.m_Number == 0){
        cout << "无预约记录！" << endl;
        return;
    }
    for(int i = 0; i < bf.m_Number; i ++){
        // string利用c_str()转const char*
        // 利用atoi(const char*)转inti
        if(this->m_Id ==atoi(bf.m_Context[i]["stuId"].c_str())){// 找到自身预约
            cout << "预约日期：周" << bf.m_Context[i]["date"];
            string interval = (atoi(bf.m_Context[i]["interval"].c_str()) == 1) ? "上午":"下午";
            cout << "\t时间段：" << interval;
            cout << "\t机房编号：" << bf.m_Context[i]["roomId"];
            string state;
            // 1审核中，2已预约，-1预约失败，0取消预约
            if(bf.m_Context[i]["state"] == "1"){
                state = "审核中";
            }
            else if(bf.m_Context[i]["state"] == "2"){
                state = "预约成功";
            }
            else if(bf.m_Context[i]["state"] == "-1"){
                state = "预约失败";
            }
            else{
                state = "预约取消";
            }
            cout << "\t预约状态：" << state << endl;
        }
    }
}
// 查看所有预约状态
void Student::checkAllBookState(){
    BookFile bf;
    if(bf.m_Number == 0){
        cout << "无预约记录！" << endl;
        return;
    }
    for(int i = 0; i < bf.m_Number; i ++){
        cout << i+1 << "、";
        cout << "预约日期：周" << bf.m_Context[i]["date"];
        string interval = (atoi(bf.m_Context[i]["interval"].c_str()) == 1) ? "上午":"下午";
        cout << "\t时间段:" << interval;
        cout << "\t学号：" << bf.m_Context[i]["stuId"];
        cout << "\t姓名：" << bf.m_Context[i]["stuName"];
        cout << "\t机房编号：" << bf.m_Context[i]["roomId"];
        string state;
        // 1审核中，2已预约，-1预约失败，0取消预约
        if(bf.m_Context[i]["state"] == "1"){
            state = "审核中";
        }
        else if(bf.m_Context[i]["state"] == "2"){
            state = "预约成功";
        }
        else if(bf.m_Context[i]["state"] == "-1"){
            state = "预约失败";
        }
        else{
            state = "预约取消";
        }
        cout << "\t预约状态：" << state << endl;
    }
}
// 取消预约
void Student::cancelBook(){
    BookFile bf;
    if(bf.m_Number == 0){
        cout << "无预约记录！" << endl;
        return;
    }
    cout << "审核中或者预约中的记录可以取消，请输入取消的记录：" << endl;
    int index = 1;
    vector<int> v;// 存放在最大容器中的下标编号
    for(int i = 0; i < bf.m_Number; i ++){
        // 先判断是自身的学号
        if(this->m_Id ==atoi(bf.m_Context[i]["stuId"].c_str())){
           // 筛选状态
            if(bf.m_Context[i]["state"] == "1" || bf.m_Context[i]["state"] == "2"){
                v.push_back(i);
                cout << index ++ << "、";
                cout << "预约日期：周" << bf.m_Context[i]["date"];
                string interval = (atoi(bf.m_Context[i]["interval"].c_str()) == 1) ? "上午":"下午";
                cout << "\t时间段:" << interval;
                cout << "\t机房编号：" << bf.m_Context[i]["roomId"];
                string state;
                // 1审核中，2已预约，-1预约失败，0取消预约
                if(bf.m_Context[i]["state"] == "1"){
                    state = "审核中";
                }
                else if(bf.m_Context[i]["state"] == "2"){
                    state = "预约成功";
                }
                cout << "\t预约状态：" << state << endl;
            }
        }
    }
    cout << "请输入取消的记录，0代表返回" << endl;
    int select = 0;
    while (true) {
        cin >> select;
        if(select >= 0 && select <= v.size()){
            if(select == 0) break;
            bf.m_Context[v[select-1]]["state"] = "0";
            bf.updateBook();
            cout << "取消预约成功！" << endl;
            break;
        }
        cout << "输入无效，请重新输入！" << endl;
    }
}
