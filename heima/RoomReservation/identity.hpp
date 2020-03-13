//
//  identity.hpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef identity_hpp
#define identity_hpp

#include <iostream>

using namespace std;

// 身份抽象类
class Identity{
public:
    virtual void operatorMenu() = 0;// 操作菜单(纯虚函数)
    virtual ~Identity(){};
public:
    string m_Name;// 用户名
    string m_Passwd;// 密码
};

#endif /* identity_hpp */
