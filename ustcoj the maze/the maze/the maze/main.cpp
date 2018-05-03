//
//  main.cpp
//  the maze
//
//  Created by 姜庆彩 on 2018/4/26.
//  Copyright © 2018年 姜庆彩. All rights reserved.
//



//这个题目一开始没看明白，参考了一下网上的代码：https://blog.csdn.net/wood_water/article/details/11982993
//d变量用于定义‘左’

#include <iostream>
#define length 101
#define max_step 10001
using namespace std;

const int dx[]={0,-1,0,1};
const int dy[]={1,0,-1,0};
const char direc[] = {"ENWS"};
char mat[length][length];
char path[max_step];

bool checkleft(int x,int y,int d){
    d=(d+1)%4;
    x+=dx[d];y+=dy[d];
    return mat[x][y]=='#';
}
bool checkst(int x,int y,int d){
    x+=dx[d];y+=dy[d];
    return mat[x][y]=='#';
}
void solve(){
    int i,j;
    int n;
    int d;
    int start_x,start_y,end_x,end_y;
    cin>> n;
    for(i=1; i<=n; ++i)
        cin>>(mat[i]+1);
    for(i=0;i<=n+1;++i)
        mat[i][0]=mat[0][i]=mat[n+1][i]=mat[i][n+1]='#';//四周是墙
    cin>> start_x>> start_y>> end_x>> end_y;
    if(start_x==1 && start_y==1) d=0;
    else if(start_x==1 && start_y==n) d=3;
    else if(start_x==n && start_y==n) d=2;
    else d=1;
    if(start_x==end_x && start_y==end_y){
        cout<<0<<endl;
    }
    for(i=1;i<=10000;++i){
        if(!checkleft(start_x,start_y,d)){
            d=(d+1)%4;
            start_x+=dx[d];start_y+=dy[d];
            path[i]=direc[d];
        }else {
            for(j=0;j<=3;++j){
                if(!checkst(start_x,start_y,d))break;
                d=(d+3)%4;
            }
            if(checkst(start_x,start_y,d))break;
            start_x+=dx[d];start_y+=dy[d];
            path[i]=direc[d];
        }
        if(start_x==end_x && start_y==end_y){
            cout<<i<<endl;
            for(j=1;j<=i;++j) cout<<path[j];
            cout<<endl;
            return;
        }
    }
    cout<<"Edison ran out of energy.\n";
}

int main(int argc, const char * argv[]) {
    int i;
    int case_count;
    cin>> case_count;
    for(i=1; i<=case_count; ++i){
        cout<< "Case #"<< i<< ": ";
        solve();
    }
    return 0;
}
