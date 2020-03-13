//
//  main.cpp
//  cppCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>

#define PI 3.14

using namespace std;

class Circle{
public:// 访问权限为公共
    //属性
    int r_m;// 半径
    //行为
    double calcZC(){// 获取园的周长
        return 2*PI*r_m;
    }
};

int main(int argc, const char * argv[]) {
    Circle c1;//创建具体的圆（对象），实例化
    c1.r_m = 10;// 给圆对象属性赋值
    cout << "圆的周长=" << c1.calcZC() << endl;
    
    return 0;
}
