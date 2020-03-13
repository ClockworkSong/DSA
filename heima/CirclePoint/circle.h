#pragma once
#include <iostream>

using namespace std;

// 圆类
class Circle{
public:
    // 设置半径
    void setR(int r);
    // 获取半径
    int getR();
    // 设置圆心
    void setC(Ponit c);
    // 获取圆心
    Ponit getC();
private:
    int R_m;// 半径
    // 在类中可以让k另一个类作为成员
    Ponit C_m;// 圆心
};
