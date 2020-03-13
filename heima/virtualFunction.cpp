//
//  main.cpp
//  calculate
//
//  Created by clockworkSong on 2020/2/22.
//  Copyright © 2020 clockworkSong. All rights reserved.
// 利用多态技术实现本案例，提供抽象制作饮品类，提供子类制作咖啡和茶叶

#include <iostream>

using namespace std;

class AbstractDrinking{
public:
    virtual void Boil() = 0;// 煮水
    virtual void Brew() = 0;// 冲泡
    virtual void Pour() = 0;// 倾倒
    virtual void Options() = 0;// 可选项
    //制作饮品
    void makeDrink(){
        Boil();
        Brew();
        Pour();
        Options();
    }
    virtual ~AbstractDrinking(){
        cout << "Base ~" << endl;
    }
};

// 制作咖啡
class Coffee : public AbstractDrinking{
public:
    void Boil(){
        cout << "煮山泉水" << endl;
    }
    void Brew(){
        cout << "冲泡咖啡" << endl;
    }
    void Pour(){
        cout << "倾倒" << endl;
    }
    void Options(){
        cout << "可选项：加牛奶" << endl;
    }
    ~Coffee(){
        cout << "Coffee ~" << endl;
    }
};
// 制作茶叶
class Tea : public AbstractDrinking{
public:
    void Boil(){
        cout << "煮自来水" << endl;
    }
    void Brew(){
        cout << "冲泡茶叶" << endl;
    }
    void Pour(){
        cout << "倾倒杯中" << endl;
    }
    void Options(){
        cout << "可选项：加茶叶" << endl;
    }
    ~Tea(){
        cout << "Tea ~" << endl;
    }
};

// 制作函数
void doWork(AbstractDrinking* p){
    p->makeDrink();
    delete p;// 释放
}

void test01(){
    // 制作咖啡
    doWork(new Coffee);
    cout << "-----------" << endl;
    // 制作茶叶
    doWork(new Tea);
}

int main(int argc, const char * argv[]) {
    test01();
    
    return 0;
}
