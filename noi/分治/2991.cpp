//http://noi.openjudge.cn/ch0204/2991/
#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
using namespace std;
int zhubei[201];
char shu[201];
int main()
{
    int i,j,k,r;
    zhubei[0]=2011;
    int tmp;
    for(i=1;i<200;i++)
    {
        tmp=1;
        for(j=0;j<10;j++)
        {
            tmp*=zhubei[i-1];
            tmp%=10000;
            //printf("tmp %d\n",tmp);
        }
        zhubei[i]=tmp;
        //printf("zhunbei %d is %d\n",i,tmp);
    }
    int n;
    cin>>n;
    int len;
    int res=1;
    int p,q;
    while(n-->0)
    {
        cin>>shu;
        res=1;
        len=strlen(shu);
        //cout<<shu<<endl;
        for(i=0;i<len;i++)
        {
            p=shu[i]-'0';
            //cout<<"con"<<p<<endl;
            q=1;
            if(p>0){
            for(j=0;j<p;j++)
            {
                q*=zhubei[len-1-i];
                q%=10000;
            }
            }
            //else if(j==0){q=1;}
            res*=q;
            res%=10000;
        }
        cout<<res<<endl;

    }
}
