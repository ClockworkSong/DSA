//
//  main.cpp
//  calculate
//
//  Created by clockworkSong on 2020/2/22.
//  Copyright © 2020 clockworkSong. All rights reserved.
// 多态案例电脑组装

#include <iostream>

using namespace std;

// 抽象CPU类
class CPU{
public:
    // 抽象的计算函数
    virtual void calculate() = 0;
};

// 抽象显卡类
class VideoCard{
public:
    // 抽象的显示函数
    virtual void display() = 0;
};

// 抽象内存条类
class Memory{
public:
    // 抽象的存储函数
    virtual void storage() = 0;
};

// 电脑类
class Computer{
public:
    Computer(CPU* cpu, VideoCard* vc, Memory* mem){
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    // 提供工作的函数
    void work(){
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }
    // 提供析构函数 释放3个电脑零件
    ~Computer(){
        if(m_cpu!=NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        if(m_mem!=NULL){
            delete m_mem;
            m_mem = NULL;
        }
        if(m_vc!=NULL){
            delete m_vc;
            m_vc = NULL;
        }
    }
private:
    CPU * m_cpu;// CPU零件指针
    VideoCard * m_vc;// 显卡零件指针
    Memory * m_mem;// 内存条零件指针
};

// 具体的厂商
// Intel
class IntelCPU : public CPU{
public:
    virtual void calculate(){
        cout << "Intel calculate" << endl;
    }
};

class IntelVideoCard : public VideoCard{
public:
    virtual void display(){
        cout << "Intel display" << endl;
    }
};

class IntelMemory : public Memory{
public:
    virtual void storage(){
        cout << "Intel storage" << endl;
    }
};

// AMD
class AMDCPU : public CPU{
public:
    virtual void calculate(){
        cout << "AMD calculate" << endl;
    }
};

class AMDVideoCard : public VideoCard{
public:
    virtual void display(){
        cout << "AMD display" << endl;
    }
};

class AMDMemory : public Memory{
public:
    virtual void storage(){
        cout << "AMD storage" << endl;
    }
};

void test01(){
    // 第一台电脑
    CPU* IntelCpu = new IntelCPU;
    VideoCard* IntelVc = new IntelVideoCard;
    Memory* IntelMem = new IntelMemory;
    
    // 创建第一台电脑
    Computer* c1 = new Computer(IntelCpu, IntelVc, IntelMem);
    c1->work();
    delete c1;
    cout << "--------------" << endl;
    // 创建第二台电脑
    Computer* c2 = new Computer(new AMDCPU, new AMDVideoCard, new AMDMemory);
    c2->work();
    delete c2;
    
    cout << "--------------" << endl;
    // 创建第三台电脑
    Computer* c3 = new Computer(new AMDCPU, new IntelVideoCard, new AMDMemory);
    c3->work();
    delete c3;
}

int main(int argc, const char * argv[]) {
    test01();
    return 0;
}
