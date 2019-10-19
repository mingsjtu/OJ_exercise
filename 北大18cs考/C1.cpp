#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
 
using namespace std;
int w,h,num[1000],l;
int dx[4]= {1,0,-1,0};
int dy[4]= {0,-1,0,1};
char mmap[100][100];
int vis[100][100];
void ddfs(int s,int e)
{
    int i,j;
    mmap[s][e]='*';
    for(i=0; i<4; i++)
    {
        int xx=s+dx[i];
        int yy=e+dy[i];
        if(xx>=0&&xx<h&&yy>=0&&yy<w&&mmap[xx][yy]=='X')
            ddfs(xx,yy);
    }
}
void dfs(int s,int e)
{
    int i,j;
    mmap[s][e]='.';
    for(i=0; i<4; i++)
    {
        int xx=s+dx[i];
        int yy=e+dy[i];
        if(xx>=h||yy>=w||xx<0||yy<0||mmap[xx][yy]=='.')
           continue;
        if(mmap[xx][yy]=='X')
        {
            ddfs(xx,yy);
            num[l]++;
        }
        if(mmap[xx][yy]=='*')
            dfs(xx,yy);
    }
}
 
int main()
{
    int i,j,k=1;
    while(~scanf("%d%d",&w,&h))
    {
        if(!w&&!h)break;
        memset(mmap,0,sizeof(mmap));
        memset(num,0,sizeof(num));
        l=0;
        for(i=0; i<h; i++)
            scanf("%s",mmap[i]);
        for(i=0; i<h; i++)
        {
            for(j=0; j<w; j++)
            {
                if(mmap[i][j]=='*')
                {
                    dfs(i,j);
                    l++;
                }
            }
 
        }
        printf("Throw %d\n",k++);
        sort(num,num+l);
        for(i=0; i<l-1; i++)
        {
            printf("%d ",num[i]);
        }
        printf("%d",num[i]);
        printf("\n\n");
    }
    return 0;
}

