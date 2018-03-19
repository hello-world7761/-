//
//  main.cpp
//  shortest prefix
//
//  Created by 姜庆彩 on 2018/3/19.
//  Copyright © 2018年 姜庆彩. All rights reserved.
//

#include <iostream>
#include <string.h>
#define maxnum 1000
#define maxstr 21
using namespace std;
int main(int argc, const char * argv[]) {
    char arr[maxnum][maxstr];
    int count = 0;
    while((cin >> arr[count])&& arr[count]!=NULL)
        count++;
    int len;
    char chs[maxstr],chs2[maxstr];
    int i, j, k;
    for(int i = 0; i < count; i++){
        len = strlen(arr[count]);
        for(j = 1;j < len; j++)
        {
            strcpy(chs,arr[i]);
            chs[j] = '\0';
            
            for(k = 0; k < count; k++)
            {
                strcpy(chs2,arr[k]);
                chs2[j] = '\0';
                if(!strcmp(chs,chs2) && k!=i) break;
            }
            
            if(k >= count) break;
        }
        if(j == len) printf("%s %s\n",arr[i],arr[i]);
        else printf("%s %s\n",arr[i],chs);
    }
    return 0;
}
