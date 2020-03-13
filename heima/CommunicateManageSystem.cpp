//
//  main.cpp
//  ComManSys
//  通信录管理系统
//  Created by clockworkSong on 2020/2/20.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>
#include <string.h>
//#include <stdlib.h>

#define MAX 1000

using namespace std;

//联系人信息结构体
typedef struct Student{
    string name;// 姓名
    int sex;// 性别1为男，0为女
    int age;// 年龄
    string phone;// 电话
    string address;// 地址
}stu_t;

//联系人通讯录结构体
typedef struct AddressBooks{
    //通讯录联系人数组
    struct Student array[MAX];
    //当前联系人个数
    int size;
}book_t;

//判断通信录是否已满
bool isFull(const book_t* bk){
    return bk->size == MAX;
}

//判断通信录是否为空
bool isEmpty(const book_t* bk){
    return bk->size == 0;
}

//判断联系人是否存在，存在则返回数组下标索引号
int isExist(const book_t* bk, string name){
    for(int i=0; i<bk->size; i++){
        if(bk->array[i].name == name){
            return i;
        }
    }
    return -1;
}

//清屏
void clearMenu(){
    cout << "请输入回车继续..." << endl;
    cin.get();
    getchar();
//    system("reset");
    system("clear");
//    printf("%s","\033[1H\033[2J");
    return;
}

//删除指定联系人
void deleteStudent(book_t* bk){
    cout << "请输入删除联系人的姓名:" << endl;
    string name;
    cin >> name;
    int ret = isExist(bk, name);
    if(ret >= 0){
        for(int i=ret; i<bk->size; i++){
            bk->array[i] = bk->array[i+1];// 数据迁移
        }
        bk->size --;// 跟新通讯录人员数
        cout << "删除成功!" << endl;
    }
    else{
        cout << "查无此人，删除失败" << endl;
    }
    clearMenu();
    return;
}

//查找指定联系人
void findStudent(book_t* bk){
    cout << "请输入联系人的姓名:" << endl;
    string name;
    cin >> name;
    int i = isExist(bk, name);
    if(i >= 0){
        cout << "姓名:" << bk->array[i].name << endl;
        cout << "性别:" << string((bk->array[i].sex == 0)?"女":"男") << "\t";
        cout << "年龄:" << bk->array[i].age << "\t";
        cout << "电话:" << bk->array[i].phone << "\t";
        cout << "住址:" << bk->array[i].address << endl;
    }
    else{
        cout << "查无此人" << endl;
    }
    clearMenu();
    return;
}

//修改联系人信息
void ModifyStudent(book_t* bk){
    cout << "请输入联系人的姓名:" << endl;
    string name;
    cin >> name;
    int ret = isExist(bk, name);
    if(ret >= 0){
        char ch;
        cout << "是否需要修改姓名:(y/n)";
        cin >> ch;
        if(ch == 'y' || ch == 'Y'){
            cout << "请输入联系人的姓名:" << endl;
            string name;
            cin >> name;
            bk->array[ret].name = name;
        }
        cout << "是否需要修改性别:(y/n)";
        cin >> ch;
        if(ch == 'y' || ch == 'Y'){
            cout << "请输入联系人的性别:" << endl;
            int sex;
            cin >> sex;
            bk->array[ret].sex = sex;
        }
        cout << "是否需要修改年龄:(y/n)";
        cin >> ch;
        if(ch == 'y' || ch == 'Y'){
            cout << "请输入联系人的年龄:" << endl;
            int age;
            cin >> age;
            bk->array[ret].age = age;
        }
        cout << "是否需要修改电话:(y/n)";
        cin >> ch;
        if(ch == 'y' || ch == 'Y'){
            cout << "请输入联系人的电话:" << endl;
            string phone;
            cin >> phone;
            bk->array[ret].phone= phone;
        }
        cout << "是否需要修改地址:(y/n)";
        cin >> ch;
        if(ch == 'y' || ch == 'Y'){
            cout << "请输入联系人的地址:" << endl;
            string address;
            cin >> address;
            bk->array[ret].address = address;
        }
        cout << "修改成功!" << endl;
    }
    else{
        cout << "查无此人" << endl;
    }
    return;
}

//添加联系人
void addStudent(book_t* bk){
    if(isFull(bk)) {
        cout << "通信录已满，无法添加!" << endl;
        return;
    }
    else{
        string name;
        cout << "请输入姓名:" << endl;
        cin >> name;
        bk->array[bk->size].name = name;
        
        int sex = 0;
        cout << "请输入性别:" << endl;
        cout << "1 --- 男, 0 --- 女" << endl;
        while (true) {
            cin >> sex;
            if(sex == 0 || sex == 1){
                bk->array[bk->size].age = sex;
                break;
            }
            else{
                cout << "性别输入有误，请重新输入!" << endl;
            }
        }
        
        int age = 0;
        cout << "请输入年龄:" << endl;
        while (true) {
            cin >> age;
            if(age >= 0 && age <= 100){
                bk->array[bk->size].age = age;
                break;
            }
            else{
                cout << "年龄输入有误，请重新输入!" << endl;
            }
        }
        
        string phone;
        cout << "请输入电话:" << endl;
        cin >> phone;
        bk->array[bk->size].phone = phone;
        
        string address;
        cout << "请输入地址:" << endl;
        cin >> address;
        bk->array[bk->size].address = address;
        
        //更新通讯录人数
        bk->size ++;
        
        cout << "联系人添加成功!" << endl;
        clearMenu();
    }
    return;
}

//清空联系人
void cleanStudent(book_t* bk){
    bk->size = 0;
    cout << "联系人清除成功!" << endl;
    clearMenu();
    return;
}

//显示联系人
void showStudent(const book_t* bk){
    if(isEmpty(bk)){
        cout << "通信录为空!" << endl;
        return;
    }
    else{
        for(int i=0; i<bk->size; i++){
            cout << "姓名:" << bk->array[i].name << endl;
            cout << "性别:" << string((bk->array[i].sex == 0)?"女":"男") << "\t";
            cout << "年龄:" << bk->array[i].age << "\t";
            cout << "电话:" << bk->array[i].phone << "\t";
            cout << "住址:" << bk->array[i].address << endl;
        }
    }
    clearMenu();
    return;
}

//菜单界面
void showMenu(){
    cout << "**********************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "**********************" << endl;
}

int main(int argc, const char * argv[]) {
    //创建通信录结构头变量
    book_t bk;
    bk.size = 0;// 初始化通讯录中人数
    int select = 0;//创建用户选择输入变量
    while (true) {
        showMenu();// 菜单调用
        cin >> select;
        switch (select) {
            case 1://添加
                addStudent(&bk);//利用地址传递，可以修饰实参
                break;
            case 2://显示
                showStudent(&bk);
                break;
            case 3://删除
                deleteStudent(&bk);
                break;
            case 4://查找
                findStudent(&bk);
                break;
            case 5://修改
                ModifyStudent(&bk);
                break;
            case 6://清空
                cleanStudent(&bk);
                break;
            case 0://退出
                cout << "系统已退出，欢迎下次使用！" << endl;
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
