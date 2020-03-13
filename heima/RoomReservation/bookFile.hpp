//
//  bookFile.hpp
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef bookFile_hpp
#define bookFile_hpp

#include <iostream>
#include <map>
#include <fstream>
#include "globalFile.h"
using namespace std;

class BookFile{
public:
    BookFile();// 构造函数
    void updateBook();// 更新预约记录
public:
    int m_Number;// 记录预约条数
    map<int, map<string, string> > m_Context;// 记录所有预约信息的容器
};

#endif /* bookFile_hpp */
