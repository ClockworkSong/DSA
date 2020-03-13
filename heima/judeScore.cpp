#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
using namespace std;

/*
有5名选手ABCDE，10个评委分别对每一个选手打分，去除最高分，去除最低分，取平均分
*/

class Person{
public:
	Person(string name, int score){
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};

void createPerson(vector<Person>& v){
	string nameSeed = "ABCDE";
	int score = 0;
	for(int i = 0; i < 5; i++){
		string name = "player";
		name += nameSeed[i];
		Person p(name, score);
		// 将创建的person放入到容器中
		v.push_back(p);
	}
}

void setScore(vector<Person>& v){
	for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
		// 将评委的分数放入到deque容器中
		deque<int> d;
		for(int i = 0; i < 10; i ++){
			int score = rand() % 41 + 60;// 60~100
			d.push_back(score);
		}
		cout << "姓名：" << (*it).m_Name << "\t评委打分：";
		for(deque<int>::iterator it=d.begin(); it!=d.end(); it++){
			cout <<  *it << " ";
		}
		cout << endl;
		// 排序
		sort(d.begin(), d.end());
		// 去除最高和最低
		d.pop_back();
		d.pop_front();
		// 取平均分
		int sum = 0;
		for(deque<int>::iterator it=d.begin(); it!=d.end(); it++){
			sum += *it;
		}
		int avg = sum / d.size();
		// 将平均分赋值给选手
		it->m_Score = avg;
		cout << "姓名：" << (*it).m_Name << "\t平均分数为：" <<  it->m_Score << endl;;
	}
}

void showScore(vector<Person>& v){
	for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
		cout << "姓名：" << (*it).m_Name << "\t分数：" <<  it->m_Score << endl;;
	}
}

int main(){
	// 随机数种子
	srand((unsigned int)time(NULL));
	// 创建五名选手
	vector<Person> v;
	createPerson(v);
	// 遍历
	for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
		cout << "姓名：" << (*it).m_Name << "\t分数：" <<  it->m_Score << endl;;
	}
	// 选手打分
	setScore(v);
	// 显示分数
	showScore(v);

}