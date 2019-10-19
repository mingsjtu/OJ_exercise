//https://blog.csdn.net/da_kao_la/article/details/82319399
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
using namespace std;
int flag[2];
int x[100];//shu caozuofu 1+,2-,3*,4/
int n,k,des,res,maxv=99999;//caozuoshu , caozuofu ,jieguo
int dfs(int k ,int res,int s)
{

    int flag[4];
    if(k==n-1)
        {cout<<res<<"s"<<s<<endl;
        if(res==des)
        return s;
        else {if(res>des&&res<maxv)
            maxv=res;
            return -1;}

        }
    //+
    flag[0]=dfs(k+1,res+x[k+1],(s<<1)+0);
    flag[1]=dfs(k+1,res*x[k+1],(s<<1)+1);
    int res1;
    if(flag[0]>=0)
        return flag[0];
    else if(flag[1]>=0)
        return flag[1];
    else return -1;
}
int main()
{
    memset(x,0,sizeof(x));
    cin>>n;cin>>des;
    for(int i=0;i<n;i++)
        cin>>x[i];

    k=0;
    res=x[0];
    res=dfs(k,res,0);//fu, dangqian jieguo
    cout<<res<<endl;
    char tmp;
    int w=pow(2,n-2);
    if(res>=0)
    {
        for(k=0;k<n-1;k++)
            {
                if(res<w)tmp='+';
                if(res>=w){tmp='*';res-=w;}
                cout<<x[k]<<tmp;
                w/=2;
            }
        cout<<x[n-1]<<endl;
    }
    else cout<<maxv<<endl;
}
