//
//  main.cpp
//  seqStack
//
//  Created by clockworkSong on 2020/2/8.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    stack<int> st;
    st.push(11);
    st.push(11.22);
    st.push(22);
    int x;
    x = st.top();
    st.pop();
    cout << x << endl;
    cout << st.empty() << endl;
    cout << st.size() << endl;
    
    return 0;
}
