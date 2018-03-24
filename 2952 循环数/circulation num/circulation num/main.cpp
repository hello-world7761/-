//
//  main.cpp
//  circulation num
//
//  Created by 姜庆彩 on 2018/3/24.
//  Copyright © 2018年 姜庆彩. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int i, f, l, j, k, x;
    char a[99];
    cin>>a;
    l = strlen(a);
    x=j=f=0;
    k=l+1;
    for(i=l-1; i; i--)
    {
        x += (a[i]-'0')*k;
        if(x%10!=9) {f = 1;break;}
        x = x/10;
    }
    l = (l+1)/2;
    for(i=0;i<l; i++)
    {
        if(a[i]+a[i+l]-2*'0'!=9)
        {
            f=1;
            break;
        }
    }
    if(f) cout << '0';
    else cout << '1';
    return 0;
}
