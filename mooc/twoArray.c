//
//  main.c
//  array
//
//  Created by clockworkSong on 2020/2/7.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <stdio.h>

void func(int (*)[5], int);//函数申明

void func(int (*p)[5]/*int a[][5]*/, int k)
{
    
    
}

int main(int argc, const char * argv[]) {
    int arr[3][5];
    int (*p)[5];
    p = arr;
    
    func(arr, 3);
    
    return 0;
}
