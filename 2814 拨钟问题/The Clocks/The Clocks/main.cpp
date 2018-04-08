#include<cstdio>
#include<cstdlib>
#define MAXN 9
int clocks[MAXN+5],Trans[MAXN+5];
const int f[MAXN+5][MAXN+5]=
{
    {0},
    {0,1,1,0,1,1,0,0,0,0},
    {0,1,1,1,0,0,0,0,0,0},
    {0,0,1,1,0,1,1,0,0,0},
    {0,1,0,0,1,0,0,1,0,0},
    {0,0,1,0,1,1,1,0,1,0},
    {0,0,0,1,0,0,1,0,0,1},
    {0,0,0,0,1,1,0,1,1,0},
    {0,0,0,0,0,0,0,1,1,1},
    {0,0,0,0,0,1,1,0,1,1},
};
int op;
void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
bool check()
{
   
    for(int i=1;i<=9;i++)
    {
        int t=clocks[i];
        
        for(int j=1;j<=9;j++)
        {
            t=(t+Trans[j]*f[j][i])%4;
        }
        if(t) return 0;
    }
    return 1;
}
void print()
{
    bool flag=1;
    for(int i=1;i<=9;i++)
        for(int j=1;j<=Trans[i];j++)
            if(flag) printf("%d",i),flag=0;
            else printf(" %d",i);
}
void dfs(int x)
{
    if(check())
    {
        print();
        exit(0);
    }
    for(int i=0;i<4;i++)
    {
        Trans[x]=i;
        if(x<=9) dfs(x+1);
    }
}
int main()
{
    for(int i=1;i<=9;i++)
        read(clocks[i]);
    dfs(1);
}
