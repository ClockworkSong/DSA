//
//  main.cpp
//  arrayCpp
//
//  Created by clockworkSong on 2020/2/7.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//重载运算符输出一个向量，目的是用cout打印arr
ostream& operator << (ostream& o, const vector<int>& a)
{
    //制定打印规则
    o << "[";
    for(auto x : a)//迭代容器中所有的元素，每一个元素的临时名字就是x，将a容器中的每一个元素从前往后枚举出来
        o << x << ",";
    o << "]";
    return o;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr{1,2,3,4,5};
    cout << arr << endl;
    
    
    
    return 0;
}
