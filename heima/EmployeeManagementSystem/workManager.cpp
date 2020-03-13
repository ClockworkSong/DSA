//
//  workManager.cpp
//  EmployeeManagementSystem
//
//  Created by clockworkSong on 2020/2/25.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include "workManager.hpp"

// 构造函数的实现
WorkManager::WorkManager(){
    
    // 1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);// 读文件
    if(!ifs.is_open()){
        cout << "文件不存在！" << endl;
        // 初始化属性
        this->m_Number = 0;
        this->m_pArray = NULL;
        this->m_EmptyFlag = true;
        ifs.close();
        return;
    }
    // 2.文件存在，数据为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        // 文件为空
        cout << "文件为空！" << endl;
        // 初始化属性
        this->m_Number = 0;
        this->m_pArray = NULL;
        this->m_EmptyFlag = true;
        ifs.close();
        return;
    }
    // 3.文件存在，并且记录数据
    int num = this->getEmployeeNumber();
    //cout << "职工人数为： " << num << endl;
    this->m_Number = num;
    // 4.开辟空间，将文件中的数据存放在数组中
    this->m_pArray = new Worker*[this->m_Number];
    this->initEmployee();
    //测试打印
    /*for(int i = 0; i< this->m_Number; i++){
        cout << "职工编号：" << this->m_pArray[i]->m_Id
            << "\t职工姓名：" << this->m_pArray[i]->m_Name
            << "\t职工部门：" << this->m_pArray[i]->m_Department
            << "\t职工级别：" << this->m_pArray[i]->m_Level
        << endl;
    }*/
}

// 显示菜单的实现
void WorkManager::showMenu(){
    cout << "************************" << endl;
    cout << "*** 欢迎使用职工管理系统 ***" << endl;
    cout << "***** 1.增加职工信息 *****" << endl;
    cout << "***** 2.显示职工信息 *****" << endl;
    cout << "***** 3.删除职工信息 *****" << endl;
    cout << "***** 4.修改职工信息 *****" << endl;
    cout << "***** 5.查找职工信息 *****" << endl;
    cout << "***** 6.按照编号排序 *****" << endl;
    cout << "***** 7.清空所有信息 *****" << endl;
    cout << "***** 0.退出管理系统 *****" << endl;
    cout << "************************" << endl;
}

// 自定义回车继续
void WorkManager::returnContinue(){
    cout << "请输入回车继续..." << endl;
    cin.get();
    getchar();
}

// 退出系统
void WorkManager::exitSystem(){
    cout << "欢迎下次使用！" << endl;
    returnContinue();
    exit(0);
}

// 统计文件中人数
int WorkManager::getEmployeeNumber(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);// 读
    int id;
    string name;
    string dept;
    int level;
    int lineNum = 0;
    while (ifs >> id && ifs >> name && ifs >> dept && ifs >> level) {
        lineNum++;// 统计人数变量
    }
    return lineNum;
}
// 初始化员工
void WorkManager::initEmployee(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);// 读
    int id;
    string name;
    string dept;
    int level = 0;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dept && ifs >> level) {
        Worker* wk = NULL;
        if (level == 1){
            wk = new Employee(id, name, dept, level);
        }
        else if (level == 2){
            wk = new Manager(id, name, dept, level);
        }
        else if (level == 3){
            wk = new Boss(id, name, dept, level);
        }
        this->m_pArray[index++] = wk;
    }
    ifs.close();
}

// 添加职工
void WorkManager::addEmployee(){
    cout << "请输入添加职工数量:" << endl;
    int addNum = 0;
    cin >> addNum;
    if(addNum <= 0){
        cout << "输入有误，请重新输入！" << endl;
    }
    else{
        // 计算添加新空间大小
        int newSize = this->m_Number + addNum;// 原有+新增
        // 开辟新空间，动态存储
        Worker** newSpace = new Worker*[newSize];
        // 将原来空间下数据拷贝到新空间下
        if(this->m_pArray != NULL){
            for(int i = 0; i < this->m_Number; i++){
                newSpace[i] = this->m_pArray[i];
            }
        }
        // 批量添加新数据
        for(int i = 0; i < addNum; i++){
            int Id;
            string Name;
            string Dept;
            int Level;
            cout << "请输入第 " << i+1 << " 个新职工编号：" << endl;
            cin >> Id;
            cout << "请输入第 " << i+1 << " 个新职工姓名：" << endl;
            cin >> Name;
            cout << "请输入第 " << i+1 << " 个新职工部门：" << endl;
            cin >> Dept;
            cout << "请选择该职工的岗位：1、普通员工 2、经理 3、老板：" << endl;
            cin >> Level;
            
            Worker* wk = NULL;
            switch (Level) {
                case 1:
                    wk = new Employee(Id, Name, Dept, Level);
                    break;
                case 2:
                    wk = new Manager(Id, Name, Dept, Level);
                    break;
                case 3:
                    wk = new Boss(Id, Name, Dept, Level);
                    break;
                default:
                    break;
            }
            // 将创建职工职责保存到数组中
            newSpace[this->m_Number + i] = wk;
        }
        // 释放原有空间
        delete[] this->m_pArray;
        // 更改新空间指向
        this->m_pArray = newSpace;
        // 更新新职工的人数
        this->m_Number = newSize;
        // 更新职工不为空标志
        this->m_EmptyFlag = false;
        // 提示添加成功
        cout << "成功添加 " << addNum <<  " 位新职工！" << endl;
        // 保存信息到文件
        this->saveInformation();
    }
    // 按回车，清屏回到上一级目录
    returnContinue();
}

// 显示职工
void WorkManager::showEmployee(){
    // 判断文件是否为空
    if(this->m_EmptyFlag){
        cout << "文件不存在或者为空！" << endl;
    }
    else{
        for(int i = 0; i< this->m_Number; i++){
            // 利用多态调用程序接口
            this->m_pArray[i]->showInfo();
        }
    }
    returnContinue();
}
// 判断职工是否存在
int WorkManager::isExist(int id){
    int index = -1;
    for(int i = 0; i < this->m_Number; i++){
        if(this->m_pArray[i]->m_Id == id){
            index = i;
            break;
        }
    }
    return index;
}
// 删除职工
void WorkManager::deleteEmployee(){
    if(this->m_EmptyFlag){
        cout << "文件不存在或者为空！" << endl;
    }
    else{
        // 按照职工编号删除
        cout << "请输入想要删除职工的编号：" << endl;
        int id = 0;
        cin >> id;
        int index = this->isExist(id);
        if(-1 == index){
            cout << "删除失败，查无此人！" << endl;
        }
        else{// 可删除
            // 数据前移
            for(int i = index; i < this->m_Number - 1; i ++){
                this->m_pArray[i] = this->m_pArray[i+1];
            }
            // 更新数组中记录人员
            this->m_Number --;
            // 数据同步
            this->saveInformation();
            cout << "删除成功！" << endl;
        }
    }
    returnContinue();
}
// 修改职工信息
void WorkManager::modifyEmployee(){
    if(this->m_EmptyFlag){
        cout << "文件不存在或者为空！" << endl;
    }
    else{
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if(-1 == index){
            cout << "删除失败，查无此人！" << endl;
        }
        else{// 可修改
            // 查到编号职工
            delete this->m_pArray[index];
            int newId = 0;
            string newName = "";
            string newDept = "";
            int newLevel = 0;
            cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
            while (true) {
                cin >> newId;
                if(-1 == this->isExist(newId)){
                    break;
                }
                else{
                    cout << "输入id已存在，请重新输入：" << endl;
                }
            }
            cout << "请输入新姓名：" << endl;
            cin >> newName;
            cout << "请输入新部门：" << endl;
            cin >> newDept;
            cout << "请输入新等级（1普通员工，2经理，3老板）：" << endl;
            cin >> newLevel;
            
            Worker* wk = NULL;
            switch (newLevel) {
                case 1:
                    wk = new Employee(newId, newName, newDept, newLevel);
                    break;
                case 2:
                    wk = new Manager(newId, newName, newDept, newLevel);
                    break;
                case 3:
                    wk = new Boss(newId, newName, newDept, newLevel);
                    break;
                default:
                    break;
            }
            // 更新数据到数组中
            this->m_pArray[index] = wk;
            // 数据同步
            this->saveInformation();
            cout << "修改成功！" << endl;
        }
    }
    returnContinue();
}
// 查找职工信息
void WorkManager::SelectEmployee(){
    if(this->m_EmptyFlag){
        cout << "文件不存在或者为空！" << endl;
    }
    else{
        cout << "请输入查找方式：1编号，2姓名" << endl;
        int select = 0;
        cin >> select;
        if (1 == select){// 编号查找
            int id;
            cout << "请输入查找的编号：";
            cin >> id;
            int index = this->isExist(id);
            if(index == -1){
                cout << "查找失败，查无此人！" << endl;
            }
            else{// 查找成功并显示
                cout << "查找成功，职工信息如下：" << endl;
                this->m_pArray[index]->showInfo();
            }
        }
        else if(2 == select){
            string name;
            bool flag = false;
            cout << "请输入员工姓名：";
            cin >> name;
            for(int i=0; i<this->m_Number; i++){
                if(this->m_pArray[i]->m_Name == name){
                    cout << "查找成功，职工信息如下：" << endl;
                    this->m_pArray[i]->showInfo();
                    flag = true;
                }
            }
            if(flag == false){
                cout << "查找失败，查无此人！" << endl;
            }
        }
        else{
            cout << "输入选项有误！" << endl;
        }
    }
    returnContinue();
}
// 排序职工信息
void WorkManager::sortEmployee(){
    if(this->m_EmptyFlag){
         cout << "文件不存在或者为空！" << endl;
     }
     else{
         cout << "请输入排序方式：1升序，2降序" << endl;
         int select = 0;
         cin >> select;
         for(int i = 0; i < this->m_Number; i++){
             int minOrMax = i;
             for(int j=i+1; j < this->m_Number; j++){
                 if(select == 1){// 升序
                     if(this->m_pArray[minOrMax]->m_Id > this->m_pArray[j]->m_Id){
                         minOrMax = j;
                     }
                 }
                 else{// 降序
                     if(this->m_pArray[minOrMax]->m_Id < this->m_pArray[j]->m_Id){
                         minOrMax = j;
                     }
                 }
             }
             // 判定一开始最小值或最大值是不是计算的最小值或最大值，如果不是则交换
             if (i != minOrMax){
                 Worker* tmp = this->m_pArray[i];
                 this->m_pArray[i] = this->m_pArray[minOrMax];
                 this->m_pArray[minOrMax] = tmp;
             }
         }
         this->saveInformation();
         cout << "排序成功，排序后的结果为：" << endl;
         this->showEmployee();
     }
}
// 清空职工信息
void WorkManager::destroyEmployee(){
    if(this->m_EmptyFlag){
        cout << "文件不存在或者为空！" << endl;
    }
    else{
        cout << "确认清空？：1确认，2返回" << endl;
        int select = 0;
        cin >> select;
        if (1 == select){// 编号查找
            // 清空文件
            ofstream ofs(FILENAME, ios::trunc);// 删除后重新创建
            ofs.close();
            
            if(this->m_pArray != NULL){
                // 删除堆区每个职工对象
                for(int i = 0; i < this->m_Number; i++){
                    delete this->m_pArray[i];
                    this->m_pArray[i] = NULL;
                }
                // 删除堆区数组指针
                delete [] this->m_pArray;
                this->m_pArray = NULL;
                this->m_Number = 0;
                this->m_EmptyFlag = false;
            }
            cout << "清空成功！" << endl;
        }
    }
    returnContinue();
}

// 保存文件
void WorkManager::saveInformation(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);// 打开方式为写
    // 将每个数据写入到文件中
    for(int i = 0; i < this->m_Number; i++){
        ofs << this->m_pArray[i]->m_Id << " "
            << this->m_pArray[i]->m_Name << " "
            << this->m_pArray[i]->m_Department << " "
            << this->m_pArray[i]->m_Level << endl;
    }
    ofs.close();
}

// 析构函数的实现
WorkManager::~WorkManager(){
    
}
