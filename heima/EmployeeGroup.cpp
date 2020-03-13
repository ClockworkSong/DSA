#include <iostream>
#include <vector>
#include <map>
#include <ctime>

#define CESHI 0
#define YANFA 1
#define YINGJIAN 2

using namespace std;

// 创建员工
class Worker{

public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v){
	string nameSeed = "ABCDEFGHIJ";
	for(int i = 0; i < 10; i++){
		Worker wk;
		wk.m_Name = "employee";
		wk.m_Name += nameSeed[i];
		wk.m_Salary = rand() % 10001 + 10000;// 10~20k
		v.push_back(wk);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m){
	for(vector<Worker>::iterator it = v.begin(); it != v.end(); it++){
		// 产生随机部门编号
		int deptId = rand() % 3;// 0 1 2
		// 将员工插入到分组中
		m.insert(make_pair(deptId, *it));// key=部门, value=员工
	}
}

void showWorkerGroup(multimap<int, Worker>& m){
	cout << "测试部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CESHI);
	int count = m.count(CESHI);// 统计人数
	int index = 0;
	for(; pos != m.end() && index < count; pos++, index++){
		cout << "姓名：" << pos->second.m_Name << "工资：" << pos->second.m_Salary << endl;
	}

	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);// 统计人数
	index = 0;
	for(; pos != m.end() && index < count; pos++, index++){
		cout << "姓名：" << pos->second.m_Name << "工资：" << pos->second.m_Salary << endl;
	}

	cout << "硬件部门：" << endl;
	pos = m.find(YINGJIAN);
	count = m.count(YINGJIAN);// 统计人数
	index = 0;
	for(; pos != m.end() && index < count; pos++, index++){
		cout << "姓名：" << pos->second.m_Name << "工资：" << pos->second.m_Salary << endl;
	}
}

void test01(vector<Worker>& v){
	for(vector<Worker>::iterator it = v.begin(); it != v.end(); it++){
		cout << "姓名：" << it->m_Name << "\t薪资：" << it->m_Salary << endl;
	}
}

int main(){
	srand((unsigned int)time(NULL));
	// 1.创建员工
	vector<Worker> v;
	createWorker(v);
	test01(v);
	// 2.员工分组
	multimap<int, Worker> m;
	setGroup(v, m);
	// 3.分组显示员工
	showWorkerGroup(m);
}

