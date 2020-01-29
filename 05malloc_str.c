/*************************************************************************
	> File Name: 05malloc_str.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Tue Jan 28 10:40:51 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int main()
{
	char* str1 = NULL;
	char* str2 = NULL;

	str1 = (char*)malloc(SIZE*sizeof(char));
	strcpy(str1, "123456789");
	str2 = (char*)malloc(SIZE*sizeof(char));
	strcpy(str2, "987654321");
	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
	printf("str1len=%d, str2len=%d\n", str1_len, str2_len);
	//尝试将合并的串存储在str1中，如果str1空间不够则用realloc申请
	if(str1_len < str1_len + str2_len)
	{
		str1 = (char*)realloc(str1, (str1_len+str2_len)*sizeof(char));
	}
	//合并
	for(int i = str1_len; i < str1_len+str2_len; i ++)
	{
		str1[i] = str2[i-str1_len];
	}
	//穿的末尾要添加\0避免出错
	str1[str1_len+str2_len] = '\0';
	printf("merge str1 = %s\n", str1);
	free(str1);
	free(str2);

	return 0;
}


