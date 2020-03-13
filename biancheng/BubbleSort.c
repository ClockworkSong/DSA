/*************************************************************************
	> File Name: BubbleSort.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Thu Feb 20 13:05:46 2020
 ************************************************************************/

#include <stdio.h>
#define N 10

int getMin(int* array, int n){
	
	int min = array[0];
	for(int i=1; i<N; i++){
		if(min > array[i])
			min = array[i];
	}
	return min;
}

int main()
{
	int arr[10] = {0};
	int num=0;
	for(int i=0; i<N; i++){
		scanf("%d", &num);
		arr[i] = num;
	}
	printf("Min = %d\n", getMin(arr, N));
	return 0;
}
