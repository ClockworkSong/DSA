//
//  main.cpp
//  cppCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>

using namespace std;

// 立方体类
class Cube{
public:
    // 设置长
    void setLength(int l){
        L_m = l;
    }
    // 获取长
    int getLength(){
        return L_m;
    }
    // 设置宽
    void setWidth(int w){
        W_m = w;
    }
    // 获取宽
    int getWidth(){
        return W_m;
    }
    // 设置高
    void setHigh(int h){
        H_m = h;
    }
    // 获取高
    int getHigh(){
        return H_m;
    }
    //获取立方体面积
    int calcS(){
        return (L_m * W_m + L_m * H_m + W_m * H_m) * 2;
    }
    //获取立方体体积
    int calcV(){
        return L_m * W_m * H_m;
    }
    //利用成员函数判断两个立方体是否相等
    bool cubeIsSame(Cube &c){
        if(c.getHigh() == H_m && c.getLength() == L_m && c.getWidth() == W_m)
            return true;
        else
            return false;
    }
private:
    int L_m;// 立方体长
    int W_m;// 立方体宽
    int H_m;// 立方体高
};

// 利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2){//引用比值传递效果好，避免参数的拷贝
    if(c1.getHigh() == c2.getHigh() && c1.getWidth() == c2.getWidth() && c1.getLength() == c2.getLength())
        return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    Cube c1;
    c1.setLength(10);
    c1.setWidth(20);
    c1.setHigh(10);
    cout << "c1的面积为" << c1.calcS() << endl;
    cout << "c1的体积为" << c1.calcV() << endl;
    
    Cube c2;
    c2.setLength(10);
    c2.setWidth(20);
    c2.setHigh(10);
    cout << "c2的面积为" << c2.calcS() << endl;
    cout << "c2的体积为" << c2.calcV() << endl;
    
    cout << string(isSame(c1, c2) ? "c1和c2相等" : "c1和c2不相等") << endl;
    cout << string(c1.cubeIsSame(c2) ? "c1和c2相等" : "c1和c2不相等") << endl;
    
    return 0;
}
