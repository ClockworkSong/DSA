//
//  main.cpp
//  calculate
//
//  Created by clockworkSong on 2020/2/22.
//  Copyright © 2020 clockworkSong. All rights reserved.
//分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

#include <iostream>

using namespace std;

//普通写法
class Base{
public:
    Base(int a, int b){
        m_A = a;
        m_B = b;
    }
    
    int getResult(string oper){
        if(oper == "+"){
            return m_A + m_B;
        }
        else if(oper == "-"){
            return m_A - m_B;
        }
        else if(oper == "*"){
            return m_A * m_B;
        }
        else if(oper == "/"){
            return m_A / m_B;
        }
        else{
            cout << "Undefine" << endl;
            return 0;
        }
    }

private:
    int m_A;
    int m_B;
};

void test01(){
    Base b1(4, 2);
    cout << b1.getResult("&") << endl;
}
// 利用多态实现计算器
class AbstractCalculator{
public:
    virtual int getResult(){
        return -1;
    }
    
    int m_Num1;
    int m_Num2;
};

// 加法计算器类
class AddCalculator : public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 + m_Num2;
    }
};

// 减法计算器类
class SubCalculator : public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 - m_Num2;
    }
};

// 乘法计算器类
class MulCalculator : public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 * m_Num2;
    }
};

// 除法计算器类
class DivCalculator : public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 / m_Num2;
    }
};

void test02(){
    AbstractCalculator *p = new AddCalculator;// 创建加法计算器对象
    p->m_Num1 = 10;
    p->m_Num2 = 20;
    cout << p->getResult() << endl;
    delete p;// 销毁
    
    p = new MulCalculator;// 创建乘法计算器对象
    p->m_Num1 = 10;
    p->m_Num2 = 20;
    cout << p->getResult() << endl;
    delete p;// 销毁

}

int main(int argc, const char * argv[]) {
//    test01();
    test02();
   
    return 0;
}
