//
//  main.c
//  findC
//
//  Created by clockworkSong on 2020/2/7.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <stdio.h>

//单入口多出口
int findKey(int* a, int size, int key)
{
    for(int i=0; i<size; i++)
    {
        if(a[i] == key) return i;
    }
    return -1;//查找失败
}

//单入口单出口
int findEle(int* a, int size, int key)
{
    int flag = 0;
    int index = -1;
    for(int i=0; i<size; i++)
    {
        if(a[i] == key)
        {
            flag = 1;
            index = i;
        }
    }
    return index;//返回初值
}
//返回函数运行的状态,查找到的元素值通过指针的方式获取
int getIndex(int* a, int size, int key, int* p)
{
    if(key < 0 || key >= size)
    {
        return -1;
    }
    else
    {
        *p = a[key];
        return 0;
    }
}

int findMax(int* a, int size)
{
    int tmp = a[0];
    for(int i=1; i<size; i++)
    {
        if(a[i] > tmp) tmp = a[i];
    }
    return tmp;
}

int main(int argc, const char * argv[]) {
    int arr[10] = {1, 21, 4, 6, 7, 9};
    int key = 66;
    int result = findKey(arr, 10, key);
    printf("%d\n", result);
    
    int ret = findEle(arr, 10, key);
    printf("%d\n", ret);
    
    int index = 3;
    int value;
    int flag = getIndex(arr, 10, index, &value);
    printf("flag = %d, value = %d\n", flag, value);
    
    int max = findMax(arr, 10);
    printf("max = %d\n", max);
    return 0;
}
