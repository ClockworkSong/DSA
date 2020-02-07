"""
src zhuzi1
mid zhuzi2
tar zhuzi3
"""
def hanoi(n, src, mid, tar):
    if n == 1:
         print('%d -> %d' % (src, tar))
    else:
        hanoi(n-1, src, tar, mid)#第一步将n-1个盘子从原位置借助目标位置放到中间
        hanoi(1, src, mid, tar)#第二步最后一个盘子从原位置直接放到目标位置
        hanoi(n-1, mid, src, tar)#第三步将n-1个盘子从中间位置借助原位置放到目标位置

hanoi(4,1,2,3);
