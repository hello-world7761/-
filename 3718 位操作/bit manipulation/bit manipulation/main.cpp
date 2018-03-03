//
//  main.cpp
//  bit manipulation
//
//  Created by 姜庆彩 on 2018/3/3.
//  Copyright © 2018年 姜庆彩. All rights reserved.
//

#include <stdio.h>

#define N 16

int main(void)
{
    int n, flag, i;
    unsigned short int a, b, a1, a2;
    scanf("%d", &n);
    while(n--) {
        scanf("%hd%hd", &a, &b);
        flag = 0;
        if(a == b)
            flag = 1;
        else
            for(i=1; i<N; i++) {
                a1 = a << i;
                a2 = a >> (N - i);
                if((a1 | a2) == b) {
                    flag = 1;
                    break;
                }
            }
        printf("%s\n", flag == 1 ? "YES" : "NO");
    }
    
    return 0;
}
