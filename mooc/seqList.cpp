//
//  main.cpp
//  seqList
//
//  Created by clockworkSong on 2020/2/8.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> a;//定义向量a
    a.push_back(11);
    a.push_back(22);
    a.push_back(33);
    a.insert(a.begin(),66);
    a.insert(a.end(), 77);
    a.erase(a.begin());
    
    for(int i : a)
    {
        cout << i << ",";
    }
    cout << endl;
    vector<int>::iterator it;//迭代器
    for(it=a.begin();it!=a.end();it++)
    {
        cout << *it << ",";
    }
    cout << endl;

    return 0;
}
