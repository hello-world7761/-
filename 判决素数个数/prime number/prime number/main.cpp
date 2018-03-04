//
//  main.cpp
//  prime number
//
//  Created by 姜庆彩 on 2018/3/4.
//  Copyright © 2018年 姜庆彩. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int x, y, count = 0, a, b;
    bool flag;
    cin>> x>> y;
    a = max(x, y);
    b = min(x, y);
    for(int i=b; i<=a; ++i){
        flag = true;
        for(int j=2; j*j<=i; j++){
            if(i%j == 0){
                flag = false;
                break;
            }
        }
        if(i != 1&& flag)
            count++;
    }
    cout<< count;
    return 0;
}
