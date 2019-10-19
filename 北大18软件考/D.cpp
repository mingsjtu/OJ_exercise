#include<iostream>
#include<cstring>
#include<stdio.h>
#include <cstdio>
#include<cmath>
char a[110][110];
int I;
using namespace  std;
bool dfs(int i ,int j ,char s[],int l,int deep,int di ,int dj)
{
    if(i<0||j<0||i>=I||j>=I) {return 0;}
    if(deep>=l) return 1;
    if (a[i][j]!=s[deep]){return 0;}
    return dfs(i+di,j+dj,s,l,deep+1,di,dj);

}
void find(char s[])
{
    int leng=strlen(s),di=0,dj=0;
    bool flag=0;
    char beg=s[0];
    int i=0,j=0;
    for(i=0;i<I;i++)
        for(j=0;j<I;j++)
    {
        if(a[i][j]==s[0]){
        for(di=-1;di<=1;di++)
            for(dj=-1;dj<=1;dj++)
                if(di!=0||dj!=0)
        {flag= dfs(i+di,j+dj,s,leng,1,di,dj);
        if(flag)
        {
            cout<<i+1<<","<<j+1<<" "<<i+di*(leng-1)+1<<","<<j+dj*(leng-1)+1<<endl;
            return;
        }
        }
    }
    }
    if(!flag)cout<<"Not found"<<endl;
}
int main()
{
    cin>>I;
    int i=0,j=0;
    for(i=0;i<I;i++)
        for(j=0;j<I;j++)
        cin>>a[i][j];
    while(1)
    {
        char s[100];
        cin>>s;
        if(s[0]=='0')break;
        else
            find(s);
    }
    return 0;


}
