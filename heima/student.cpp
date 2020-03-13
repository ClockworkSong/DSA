//
//  main.cpp
//  cppCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>

using namespace std;

class Student{
public:// 访问权限为公共
    //属性
    string name_m;// 姓名
    int id_m;// 学号
    //行为
    void displayStudent(){// 显示学生信息
        cout << "姓名:" << name_m << endl;
        cout << "学号:" << id_m << endl;
    }
    //给姓名赋值
    void setName(string name){
        name_m = name;
    }
    //给学号赋值
    void setId(int id){
        id_m = id;
    }
};

int main(int argc, const char * argv[]) {
    Student stu;// 实例化
//    stu.name_m = "宋小东";
    stu.setName("sxd");
//    stu.id_m = 110102114;
    stu.setId(110119120);
    stu.displayStudent();
    return 0;
}
