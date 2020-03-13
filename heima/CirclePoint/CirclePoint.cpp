//
//  main.cpp
//  cppCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>
#include "point.h"
#include "circle.h"

//using namespace std;

// 函数的实现如下，声明在.h文件中
// 设置x
void Ponit::setX(int x){
    X_m = x;
}
// 获取x
int Ponit::getX() {
    return X_m;
}

void Ponit::setY(int y){
    Y_m = y;
}
int Ponit::getY(){
    return Y_m;
}

// 设置半径
void Circle::setR(int r){
    R_m = r;
}
// 获取半径
int Circle::getR(){
    return R_m;
}
// 设置圆心
void Circle::setC(Ponit c){
    C_m = c;
}
// 获取圆心
Ponit Circle::getC(){
    return C_m;
}

// 判断点和圆的关系
void isInCircle(Circle &c, Ponit &p){
    //计算两点之间的距离平方
    int distance =
    (c.getC().getX() - p.getX()) * (c.getC().getX() - p.getX()) +
    (c.getC().getY() - p.getY()) * (c.getC().getY() - p.getY());
    // 计算半径的平方
    int rDistance = c.getR() * c.getR();
    // 判断两者关系
    if(distance == rDistance){
        cout << "点在圆上" << endl;
    }
    else if(distance > rDistance){
        cout << "点在圆外" << endl;
    }
    else{
        cout << "点在圆内" << endl;
    }
}

int main(int argc, const char * argv[]) {
    // 创建圆
    Circle c;
    c.setR(10);
    Ponit pc;// 圆心
    pc.setX(10);
    pc.setY(0);
    // 创建点
    Ponit px;
    px.setY(10);
    px.setY(10);
    // 判断关系
    isInCircle(c, px);
    
    return 0;
}
