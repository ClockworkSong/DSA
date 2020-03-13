//
//  main.cpp
//  SpeechContest
//
//  Created by clockworkSong on 2020/2/29.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>
#include <map>
#include "speechManager.hpp"

void test01(SpeechManager& sm){
    for(map<int, Speaker>::iterator it = sm.m_M1.begin(); it != sm.m_M1.end(); it++){
        cout << "选手编号：" << it->first << "\t姓名：" << it->second.m_Name << "\t分数：" << it->second.m_Score[0] << endl;
    }
}

int main(int argc, const char * argv[]) {
    SpeechManager sm;// 创建管理类对象]
//    test01(sm);// 打印测试
    int opt = 0;
    while (true) {
        sm.showMenu();
        cout << "请输入您的选择: ";
        cin >> opt;
        switch (opt) {
            case 1:// 开始比赛
                sm.startSpeech();
                break;
            case 2:// 查看记录
                sm.showRecord();
                break;
            case 3:// 清空记录
                sm.clearRecord();
                break;
            case 0:// 退出系统
                sm.exitSystem();
                break;
            default:
            break;
        }
    }
    
    return 0;
}
