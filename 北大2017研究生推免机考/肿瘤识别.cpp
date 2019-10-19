#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;
int N;
int map[105][105];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool isbian(int x,int y)
{
    int i=0,nx,ny;

    if(map[x][y]>50)
        return false;
    if(x==0||x==N-1||y==0||y==N-1)
        return true;
    for(i=0;i<4;i++)
    {
        nx=dx[i]+x;
        ny=dy[i]+y;
        if(nx>=N||nx<0||ny>=N||ny<0)
            continue;
        if(map[nx][ny]>50)
            return true;
    }
    return false;
}
int main()
{
cin>>N;
int i,j,s=0;
for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    {
    cin>>map[i][j];
    if(map[i][j]<=50)
        s++;
    }
int zhou=0;
for(i=0;i<N;i++)
    for(j=0;j<N;j++)
 {

 {
        if(isbian(i,j))
            zhou++;
    }
}
cout<<s<<' '<<zhou<<endl;
}
