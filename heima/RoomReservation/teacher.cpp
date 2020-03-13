//
//  teacher.cpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include "teacher.hpp"

// 默认构造函数
Teacher::Teacher(){
    
}
// 有参构造
Teacher::Teacher(int id, string name, string passwd){
    // 初始化属性
    this->m_Id = id;
    this->m_Name = name;
    this->m_Passwd = passwd;
    
}
// 菜单界面
void Teacher::operatorMenu(){
    cout << "**************************" << endl;
    cout << "******** 1.查看预约 *******" << endl;
    cout << "******** 2.审核预约 *******" << endl;
    cout << "******** 0.注销登录 *******" << endl;
    cout << "**************************" << endl;
}
// 查看所有预约状态
void Teacher::checkAllBookState(){
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
// 审核预约
void Teacher::validBook(){
    BookFile bf;
    if(bf.m_Number == 0){
        cout << "无预约记录！" << endl;
        return;
    }
    vector<int> v;
    int index = 0;
    cout << "待审核的预约记录如下：" << endl;
    for(int i = 0; i < bf.m_Number; i ++){
        // 筛选状态
        if(bf.m_Context[i]["state"] == "1"){
            v.push_back(i);
            cout << ++ index << "、";
            cout << "预约日期：周" << bf.m_Context[i]["date"];
            string interval = (atoi(bf.m_Context[i]["interval"].c_str()) == 1) ? "上午":"下午";
            cout << "\t时间段:" << interval;
            cout << "\t学号：" << bf.m_Context[i]["stuId"];
            cout << "\t姓名：" << bf.m_Context[i]["stuName"];
            cout << "\t机房编号：" << bf.m_Context[i]["roomId"];
            string state = "审核中";
            cout << "\t预约状态：" << state << endl;
        }
    }
#if 1
    cout << "请输入审核的预约记录，0代表返回" << endl;
    int select = 0;
    int opt = 0;// 接收预约结果的记录
    while (true) {
        cin >> select;
        if(select >= 0 && select <= v.size()){
            if(select == 0) break;
            cout << "请输入审核结果：1通过，2不通过" << endl;
            cin >> opt;
            if(opt == 1){
                // 通过
                 bf.m_Context[v[select-1]]["state"] = "2";
            }
            else{
                // 不通过
                 bf.m_Context[v[select-1]]["state"] = "-1";
            }
            bf.updateBook();
            cout << "审核预约成功！" << endl;
            break;
        }
        cout << "输入无效，请重新输入！" << endl;
    }
#endif
}
