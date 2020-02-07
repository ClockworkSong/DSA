//
//  main.cpp
//  findCpp
//
//  Created by clockworkSong on 2020/2/7.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>//find()

using namespace std;

ostream& operator << (ostream& o, vector<int>& a)
{
    o << "[";
    for(auto x : a)
        o << x << ",";
    o << "]";
    return o;
}

int main(int argc, const char * argv[]) {
    
    vector<int> arr{11,21,31,41,51};//容器类
    cout << arr << endl;
    
    vector<int>::iterator it;//迭代器
    for(it = arr.begin(); it != arr.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    int value = 42;
    it = find(arr.begin(), arr.end(), value);
    if(it != arr.end()) cout << *it << endl;
    
    return 0;
}
