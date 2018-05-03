//
//  main.cpp
//  maze
//
//  Created by 姜庆彩 on 2018/4/26.
//  Copyright © 2018年 姜庆彩. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#define size 51
using namespace std;

bool color[size][size];
int num_of_the_same_color;
int arr[size][size];
int max_num;
int color_count;

void dfs(int x, int y){
    if(color[x][y] != false)
        return;
    else{
        color[x][y] = true;
        num_of_the_same_color ++;
    }
    if((arr[x][y]&1) == 0) dfs(x,y-1);
    if((arr[x][y]&2) == 0) dfs(x-1,y);
    if((arr[x][y]&4) == 0) dfs(x,y+1);
    if((arr[x][y]&8) == 0) dfs(x+1,y);
}

int main(int argc, const char * argv[]) {
    int n,m;
    int i,j;
    cin>> m>> n;
    for(i=0; i<m; i++){
        for(j=0; j<n;j++){
            cin>> arr[i][j];
        }
    }
    for(i=0; i<m; i++){
        for(j=0 ;j<n; j++){
            if(color[i][j] == false){
                num_of_the_same_color = 0;
                dfs(i, j);
                color_count++;
                if(num_of_the_same_color > max_num) max_num = num_of_the_same_color;
            }
        }
    }
    cout<< color_count<< endl;
    cout<< max_num<< endl;
    return 0;
}
