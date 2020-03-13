//
//  speechManager.hpp
//  SpeechContest
//
//  Created by clockworkSong on 2020/2/29.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef speechManager_hpp
#define speechManager_hpp

#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>
#include <string>
#include <ctime>
#include "speaker.hpp"

#define FILENAME "data.csv"

using namespace std;

// 设计演讲管理类
class SpeechManager{
/*
功能描述：
1.提供菜单界面与用户交互
2.对演讲比赛流程进行控制
3.与文件的读写交互
*/
public:
    SpeechManager();// 构造函数声明
    void initSpeech();// 初始化容器和属性
    void createSpeaker();// 创建12名选手
    void startSpeech();// 开始比赛
    void speechDraw();// 抽签
    void speechContest();// 比赛
    void showMenu();// 功能菜单
    void showScore();// 显示得分
    void saveRecord();// 比赛记录
    void loadRecord();// 读取记录
    void showRecord();// 显示往届记录
    void returnContinue();// 回车继续
    void clearRecord();// 清空记录
    void exitSystem();// 退出系统
    ~SpeechManager();// 析构函数声明
public:
    // 成员属性
    vector<int> m_V1;// 保存第一轮比赛选手编号容器
    vector<int> m_V2;// 第一轮晋级选手编号容器
    vector<int> m_V3;// 胜出前三选手编号容器
    map<int, Speaker> m_M1;// 存放编号以及对应具体选手容器
    int m_Round;// 存放比赛轮数
    bool m_existFlag;// 判断文件是否为空标志位
    map<int, vector<string> > m_Record;// 存放往届记录容器
};


#endif /* speechManager_hpp */
