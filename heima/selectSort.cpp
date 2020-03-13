#include <iostream>

using namespace std;

//实现通用对数组进行排序的函数

template<typename T>
void mySwap(T& a, T& b){
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void mySort(T arr[], int len){
	for(int i = 0; i < len; i++){
		int maxIndex = i;// 最大值下标
		for(int j = i+1; j < len; j++){
			if(arr[maxIndex] < arr[j]){
				maxIndex = j;
			}
		}
		if (maxIndex != i){
			mySwap(arr[maxIndex], arr[i]);
		}
	}
}

template<typename T>
void display(T* arr, int len){
	for(int i = 0; i < len; i++){
		cout << arr[i] << " " ;
	}
	cout << endl;
}

void test01(){
	char arr[] = "bascff";
	int size = sizeof(arr) / sizeof(char);
	mySort(arr, size);
	display(arr, size);
}

void test02(){
	int arr[] = {7, 5, 2, 4, 34, 4, 55, 5, 5};
	int size = sizeof(arr) / sizeof(int);
	mySort(arr, size);
	display(arr, size);
}

int main(){
	test01();
	test02();
}
