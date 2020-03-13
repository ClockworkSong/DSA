//
//  bookFile.cpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include "bookFile.hpp"

// 构造函数
BookFile::BookFile(){
    ifstream ifs;
    ifs.open(BOOK_FILE, ios::in);
    
    string date;// 日期
    string interval;// 时间段
    string stuId;// 学生编号
    string stuName;// 学生姓名
    string roomId;// 机房编号
    string state;// 预约状态
    
    this->m_Number = 0;// 记录条数
    
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs
        >> stuName && ifs >> roomId && ifs >> state) {
        string key;
        string value;
        map<string, string> m;
        // 截取日期
        size_t pos = date.find(":");
        if(pos != -1){
            key = date.substr(0, pos);
            value = date.substr(pos+1, date.size()-pos-1);
            m.insert(make_pair(key, value));
        }
        // 截取时间段
        pos = interval.find(":");
        if(pos != -1){
            key = interval.substr(0, pos);
            value = interval.substr(pos+1, interval.size()-pos-1);
            m.insert(make_pair(key, value));
        }
        // 截取学号
        pos = stuId.find(":");
        if(pos != -1){
            key = stuId.substr(0, pos);
            value = stuId.substr(pos+1, stuId.size()-pos-1);
            m.insert(make_pair(key, value));
        }
        // 截取姓名
        pos = stuName.find(":");
        if(pos != -1){
            key = stuName.substr(0, pos);
            value = stuName.substr(pos+1, stuName.size()-pos-1);
            m.insert(make_pair(key, value));
        }
        // 截取机房编号
        pos = roomId.find(":");
        if(pos != -1){
            key = roomId.substr(0, pos);
            value = roomId.substr(pos+1, roomId.size()-pos-1);
            m.insert(make_pair(key, value));
        }
        // 截取预约状态
        pos = state.find(":");
        if(pos != -1){
            key = state.substr(0, pos);
            value = state.substr(pos+1, state.size()-pos-1);
            m.insert(make_pair(key, value));
        }
        // 将小map容器放入到大的map容器
        this->m_Context.insert(make_pair(this->m_Number, m));
        this->m_Number ++;
    }
    ifs.close();
    // 测试大map容器
//    for(map<int, map<string, string> >::iterator it = m_Context.begin(); it != m_Context.end(); it++){
//        cout << "条数key=" << it->first << " value="  << endl;
//        for(map<string, string>::iterator mit= it->second.begin(); mit != it->second.end(); mit ++){
//            cout << " key=" << mit->first << " value="  << mit->second << " ";
//        }
//        cout << endl;
//    }
}
// 更新预约记录
void BookFile::updateBook(){
    if(this->m_Number == 0) return;
    ofstream ofs;
    ofs.open(BOOK_FILE, ios::out | ios::trunc);
    for(int i = 0; i < m_Number; i ++){
        ofs << "date:" << this->m_Context[i]["date"] << " ";
        ofs << "interval:" << this->m_Context[i]["interval"] << " ";
        ofs << "stuId:" << this->m_Context[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_Context[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_Context[i]["roomId"] << " ";
        ofs << "state:" << this->m_Context[i]["state"] << endl;
    }
    ofs.close();
}
