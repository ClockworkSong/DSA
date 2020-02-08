//
//  main.cpp
//  linkList
//
//  Created by clockworkSong on 2020/2/8.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    list<int> a;
    a.push_back(11);
    a.push_back(22);
    a.push_back(33);
    a.insert(a.begin(), 66);
    a.insert(a.end(), 88);
    for(int i : a)
    {
        cout << i << ",";
    }
    cout << endl;
    
    list<int>::iterator it;
    for(it=a.begin(); it!=a.end(); it++)
    {
        cout << &(*it) << ", " << *it << endl;
    }
    cout << endl;
    
    return 0;
}
