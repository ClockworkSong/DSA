//
//  main.c
//  arrayC
//
//  Created by clockworkSong on 2020/2/7.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

/*
 高精度加法：求两个100位的十进制数字之和。
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a[11] = {0,9,8,7,6,5,4,3,2,1};
    int b[11] = {1,2,3,4,5,6,7,8,9,9};
    int sum[11] = {};
    int carry = 0;//进位标志位
    
    for(int i=0; i<11; i++)
    {
        int s = a[i] + b[i] + carry;
        carry = s/10;//如何产生进位+1
        sum[i] = s%10;
    }
    for(int i=10; i>=0; i--)
        printf("%d", sum[i]);
    putchar('\n');
    
    return 0;
}
