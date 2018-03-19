//
//  main.cpp
//  octal decimal
//
//  Created by 姜庆彩 on 2018/3/19.
//  Copyright © 2018年 姜庆彩. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
    char octal[20];
    double result = 0;
    cin >> octal;
    for(int i = 2; octal[i] != '\0'; i++){
        result += (octal[i] - '0') * pow(0.125, i-1);
    }
    printf("%s [8] = %0.45g [10]\n", octal, result);
   // cout << octal<< " [8] = "<< result<< " [10]";
    return 0;
}
