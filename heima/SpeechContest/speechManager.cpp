//
//  speechManager.cpp
//  SpeechContest
//
//  Created by clockworkSong on 2020/2/29.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include "speechManager.hpp"

// 构造函数声明
SpeechManager::SpeechManager(){
    // 初始化容器和属性
    this->initSpeech();
    // 创建12名选手
    this->createSpeaker();
    // 家在往届记录
    this->loadRecord();
}
// 初始化容器和属性
void SpeechManager::initSpeech(){
    // 容器置空
    this->m_V1.clear();
    this->m_V2.clear();
    this->m_V3.clear();
    this->m_M1.clear();
    this->m_Record.clear();
    // 初始化比赛轮数
    this->m_Round = 1;
    this->m_existFlag = false;
    //添加随机数种子
    srand((unsigned int)time(NULL));
}
// 创建12名选手
void SpeechManager::createSpeaker(){
    string nameSeed = "ABCDEFGHIJKL";
    for(int i = 0; i < 12; i ++){
        string name = "speaker";
        name += nameSeed[i];
        // 创建具体选手
        Speaker sp;
        sp.m_Name = name;
        for(int j = 0; j < 2; j ++){
            sp.m_Score[j] = 0;
        }
        // 创建选手编号，放入到容器中
        this->m_V1.push_back(i + 10001);
        // 选手编号以及对应选手放入到map容器中
        this->m_M1.insert(make_pair(i + 10001, sp));
    }
}
// 抽签
void SpeechManager::speechDraw(){
    cout << "第->" << this->m_Round << "轮比赛选手正在抽签" << endl;
    cout << "--------------------------------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;
    if(this->m_Round == 1){
        // 第一轮
        random_shuffle(m_V1.begin(), m_V1.end());
        for(vector<int>::iterator it = m_V1.begin(); it != m_V1.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    else{
        // 第二轮
        random_shuffle(m_V2.begin(), m_V2.end());
        for(vector<int>::iterator it = m_V2.begin(); it != m_V2.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    this->returnContinue();
}
// 比赛
void SpeechManager::speechContest(){
    cout << "第->" << this->m_Round << "轮比赛正式开始" << endl;
    cout << "--------------------------------" << endl;
    // 准备临时容器存放小组成绩
    multimap<double, int, greater<double> > tmp_group;
    int num = 0;// 记录人员个数，6人一组
    vector<int> v_src;// 比赛选手容器
    v_src = ((this->m_Round == 1) ? this->m_V1:this->m_V2);
    // 遍历所有选手进行比赛
    for(vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++){
        // 评委打分
        deque<int> d;
        num ++;
        for(int i = 0; i < 10; i ++){
            double score = (rand() % 401 + 600) / 10.f;// 600~1000
//            cout << score << " ";
            d.push_back(score);
        }
//        cout << endl;
        sort(d.begin(), d.end(), greater<double>());// 排序
        d.pop_front();// 去掉最高分
        d.pop_back();// 去掉最低分
        double sum = accumulate(d.begin(), d.end(), 0.0f);// 累加法
        double avg = sum / (double)d.size();// 平均分
//        cout << "编号："<< *it << "\t姓名：" << this->m_M1[*it].m_Name << "\t平均分：" << avg << endl;;
        // 将平均分放入到map中
        this->m_M1[*it].m_Score[this->m_Round-1] = avg;
        // 将打分数据放入临时小组容器
        tmp_group.insert(make_pair(avg, *it));// key是得分，value具体选手编号
        // 每6人取出前三名
        if(num % 6 == 0){
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for(multimap<double, int, greater<double> >::iterator it = tmp_group.begin(); it != tmp_group.end(); it ++){
                cout << "编号："<< it->second << "\t姓名：" << this->m_M1[it->second].m_Name << "\t分数：" << this->m_M1[it->second].m_Score[this->m_Round-1] << endl;;
            }
            // 取走前三名
            int count = 0;
            for(multimap<double, int, greater<double> >::iterator it = tmp_group.begin(); (it != tmp_group.end()) && count < 3 ; it++, count++){
                if(this->m_Round == 1){
                    m_V2.push_back((*it).second);
                }
                else{
                    m_V3.push_back((*it).second);
                }
            }
            tmp_group.clear();// 小组容器清空
        }
    }
    cout << "第" << this->m_Round << "轮比赛完毕！" << endl;
    this->returnContinue();
}
// 显示得分
void SpeechManager::showScore(){
    cout << "第->" << this->m_Round << "轮晋级的选手信息如下：" << endl;
    vector<int> v_dst;// 比赛晋级选手容器
    v_dst = ((this->m_Round == 1) ? this->m_V2:this->m_V3);
    for(vector<int>::iterator it = v_dst.begin(); it != v_dst.end(); it++){
        cout << "编号："<< *it << "\t姓名：" << this->m_M1[*it].m_Name << "\t分数：" << this->m_M1[*it].m_Score[this->m_Round-1] << endl;;
    }
    cout << endl;
    this->returnContinue();
    this->showMenu();
}

// 开始比赛
void SpeechManager::startSpeech(){
    // 第一轮开始比赛
    // 1.抽签
    this->speechDraw();
    // 2.比赛
    this->speechContest();
    // 3.晋级
    this->showScore();
    // 第二轮开始比赛
    this->m_Round ++;
    // 1.抽签
    this->speechDraw();
    // 2.比赛
    this->speechContest();
    // 3.决赛
    this->showScore();
    // 4.记录
    this->saveRecord();
    // 5.重置
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
    cout << "本届比赛完毕！" << endl;
    this->returnContinue();
}

// 比赛记录
void SpeechManager::saveRecord(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out | ios::app);// 追加方式写文件
    // 将每个选手数据写入到文件中
    for(vector<int>::iterator it = m_V3.begin(); it != m_V3.end(); it++){
        ofs << *it << "," << this->m_M1[*it].m_Score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "文件记录保存完毕！" << endl;
    this->m_existFlag = true;
}

// 读取记录
void SpeechManager::loadRecord(){
    ifstream ifs(FILENAME, ios::in);
    if(!ifs.is_open()){
        this->m_existFlag = false;
        cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }
    // 文件清空状态
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        this->m_existFlag = false;
        cout << "文件为空！" << endl;
        ifs.close();
        return;
    }
    // 文件不为空
    this->m_existFlag = true;
    ifs.putback(ch);// 将上面读取的单个字符放回来
    string data;
    int previous_years = 0;// 历届比赛
    while (ifs >> data) {
//        cout << data << endl;
        vector<string> v;// 存放选手数据
        size_t pos = -1;// 查到“，”位置的变量
        size_t start = 0;
        
        while (true) {
            pos = data.find(",", start);
            if(-1 == pos) break;// 没有找到
            else{
                string tmp = data.substr(start, pos - start);
//                cout << tmp << endl;
                v.push_back(tmp);
                start = pos + 1;
            }
        }
        this->m_Record.insert(make_pair(previous_years, v));
        previous_years ++;
    }
    ifs.close();
    for(map<int, vector<string> >::iterator it = m_Record.begin(); it != m_Record.end(); it++){
        cout << "历届编号：" << it->first << "\t冠军编号：" << it->second[0] << "\t冠军分数：" << it->second[1] << endl;
    }
}
// 显示往届记录
void SpeechManager::showRecord(){
    if(this->m_existFlag == false){
        cout << "文件为空或者文件不存在！" << endl;
    }
    else{
        for(int i = 0; i < this->m_Record.size(); i ++){
            cout << "历届编号：" << i << "\t冠军编号：" << this->m_Record[i][0] << "\t冠军分数：" << this->m_Record[i][1] << endl;
            cout << "历届编号：" << i << "\t亚军编号：" << this->m_Record[i][2] << "\t亚军分数：" << this->m_Record[i][3] << endl;
            cout << "历届编号：" << i << "\t季军编号：" << this->m_Record[i][4] << "\t季军分数：" << this->m_Record[i][5] << endl;
        }
    }
    this->returnContinue();
    return;
}
// 功能菜单
void SpeechManager::showMenu(){
    cout << "************************" << endl;
    cout << "***** 欢迎参加演讲比赛 ****" << endl;
    cout << "***** 1.开始演讲比赛 *****" << endl;
    cout << "***** 2.查看往届记录 *****" << endl;
    cout << "***** 3.清空比赛记录 *****" << endl;
    cout << "***** 0.退出比赛程序 *****" << endl;
    cout << "************************" << endl;
}

// 自定义回车继续
void SpeechManager::returnContinue(){
    cout << "请输入回车继续..." << endl;
    cin.get();
    getchar();
}
// 清空记录
void SpeechManager::clearRecord(){
    cout << "是否清空文件：1是，2否"<< endl;
    int select = 0;
    cin >> select;
    if(select == 1){
        ofstream ofs(FILENAME, ios::trunc);// 重新创建
        ofs.close();
        // 重置
        this->initSpeech();
        this->createSpeaker();
        this->loadRecord();
        cout << "清空成功！" << endl;
    }
    this->returnContinue();
}
// 退出系统
void SpeechManager::exitSystem(){
    cout << "欢迎下次使用！" << endl;
    this->returnContinue();
    exit(0);
}

// 析构函数声明
SpeechManager::~SpeechManager(){
    
}
