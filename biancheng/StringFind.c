/*************************************************************************
	> File Name: StringFind.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Thu Jan 30 10:36:18 2020
 ************************************************************************/

#include <stdio.h>
#include <string.h>

//串普通模式匹配算法的实现函数，其中B是伪主串，A是伪子串
int mate(char* B, char* A)
{
	int i = 0, j = 0;
	while(i < strlen(B) && j < strlen(A))
	{
		if(B[i] == A[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	printf("i=%d, j=%d\n", i, j);
	//跳出循环两种可能，i=len(B)说明已经遍历完主串，匹配失败；j=len(A)说明已经遍历完子串，匹配成功
	if(j == strlen(A))
	{
		return i - j + 1;
	}
	else
	{
		printf("查无此串!\n");
		return 0;
	}
}

int main()
{
	int num = mate("ababcabcacbab", "abcac");
	printf("num = %d\n", num);
	return 0;
}
