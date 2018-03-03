//
//  main.cpp
//  matrix rotate
//
//  Created by 姜庆彩 on 2018/3/3.
//  Copyright © 2018年 姜庆彩. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;
int main(int argc, const char * argv[]) {
    int mat[MAX][MAX];
    int num;
    int row;
    int i, j;
    cin>> num;
    while(num--){
        cin>> row;
        for(i = 0; i < row; i++){
            for(j = 0; j < row; j++){
                cin>> mat[i][j];
            }
        }
        for(j = 0; j < row; ++j){
            for(i= row - 1; i >= 0; --i){
                cout<< mat[i][j];
                if(i == 0)
                    cout<< endl;
                else cout<< ' ';
            }
        }
        
    }
    return 0;
}
