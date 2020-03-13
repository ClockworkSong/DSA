//
//  Header.h
//  RoomReservation
//
//  Created by clockworkSong on 2020/3/1.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#ifndef globalFile_h
#define globalFile_h

#define ADMIN_FILE      "admin.txt"// 管理员文件
#define STUDENT_FILE    "student.txt"// 学生文件
#define TEACHER_FILE    "teacher.txt"// 教师文件
#define MACHINE_FILE    "machine.txt"// 机房文件
#define BOOK_FILE       "book.txt"// 预约文件

// 机房类
class Machine{
public:
    int m_Id;// 机房号
    int m_Capacity;// 机器容量
};

#endif /* globalFile_h */
