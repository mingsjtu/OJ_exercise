//http://noi.openjudge.cn/ch0206/1768/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
int map1[105][105];//yuanshi
int map2[105][105];//qianzhuihe
int temp[105];
int a[105];
int maxn=-1280000;
int max(int a,int b)
{
    return a>b?a:b;
}
int solve()
{
    int best[105];
    best[0]=a[0];
    //cout<<a[0]<<endl;
    for(int i=1;i<n;i++)
    {

        best[i]=max(best[i-1]+a[i],a[i]);
        //printf("best %d is %d\n",i, best[i]);
    }
    int res=best[0];
    for(int i=1;i<n;i++)res=max(best[i],res);
    //printf("con max %d \n",res);

    return res;
}
int main()
{
    cin>>n;
    memset(map2,0,sizeof(map2));
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {

            cin>>map1[i][j];
            map2[i][j]=map2[i-1][j]+map1[i][j];
            }
    }
    //cout<<"ok\n";
    for(i=0;i<n;i++)
    {
        a[i]=map2[0][i];
    }
    maxn=max(maxn,solve());
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            //printf("con %d , %d\n",i,j);
            for(k=0;k<n;k++)
            {

                a[k]=map2[j][k]-map2[i][k];
                //cout<<a[k]<<' ';
            }
            //cout<<endl;
            maxn=max(maxn,solve());
        }
    }
    cout<<maxn<<endl;
}
