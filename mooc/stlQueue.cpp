//
//  stlQueue.cpp
//  cppCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    queue<int> q;
    q.push(11);
    q.push(22);
    int x;
    x = q.front();//获取队首元素
    cout << x << endl;
    q.pop();
    x = q.front();//获取队首元素
    cout << x << endl;
    
    return 0;
}
