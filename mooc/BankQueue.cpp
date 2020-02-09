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
    int N;
    cin >> N;
    queue<string> q;
    string op, id;
    cin >> op;
    while (op != "#") {
        if(op == "In")
        {
            cin >> id;
            if(q.size() == N)
                cout << id << " rejected." << endl;
            else{
                q.push(id);
                cout << id << " joined. Total:" << q.size() << endl;
            }
        }
        else{
            if(q.empty()){
                cout << "No one!" << endl;
            }
            else{
                id = q.front();
                q.pop();
                cout << id << " called. Total:" << q.size() << endl;
            }
        }
        cin >> op;
    }
    return 0;
}
