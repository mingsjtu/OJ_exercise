#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cash,N;
int qian[200];
int dp[100001];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int i,j,k;
    int tmp,tmp1;
    int c;
    while(cin>>cash>>N)
    {
        //cout<<"case"<<cash<<N<<endl;

        int cnt=0;
        for(i=0;i<N;i++)
        {
            cin>>tmp>>tmp1;
            if(tmp*tmp1==0)
                continue;
            c=1;
            while(tmp-c>0)
            {
                //if(tmp1*c<=cash)
                qian[cnt++]=tmp1*c;
                tmp-=c;
                //cout<<tmp1*c<<endl;
                c*=2;
            }
            qian[cnt++]=tmp1*tmp;
        }
        if(!cash||!N)
        {
        cout<<0<<endl;
        //cin>>cash>>N;
        continue;
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<cnt;i++)
        {
            for(j=cash;j>=qian[i];j--)
            {
            dp[j]=max(dp[j],dp[j-qian[i]]+qian[i]);
            }
            //printf("at %d is %d\n",i,dp[i]);
        }
        cout<<dp[cash]<<endl;
    }
}
