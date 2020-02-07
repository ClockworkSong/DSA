/*************************************************************************
	> File Name: recursion.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Sun Jan 12 23:00:19 2020
 ************************************************************************/

#include <stdio.h>

//递归求n!函数实现
int factorial(int n)
{
	if(n == 0) return 1;
	int ret = n*factorial(n-1);
	return ret;
}

//已知有数组a[],要求利用递归实现求n个数中的最大值
//a[]={0,1,2,...,n-1};
int findMax(int a[], int n)
{
	int tmp;
	if(n<=1) return a[0];
	tmp = findMax(a, n-1);
	int ret = a[n-1] >= tmp ? a[n-1] : tmp;
	return ret;
}

int main()
{
	printf("5!=%d\n", factorial(5));
	int a[]={0,2,4,6,8};
	printf("findMax=%d\n", findMax(a,5));
	return 0;
}
