#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<list>
#include<stack>
using namespace std;
int main()
{
    int k=0;//实验次数
    while(1)
    {

    int my[1000],m,n,win=0;
    k++;
    cin>>m>>n;//有m个人，有n个牌
    //cout<<"ok"<<endl;
    if(m==0&&n==0)break;
    for(int i=0;i<n;i++)
    {
        cin>>my[i];
    }
    sort(my,my+n);
    int min1=my[0];
    int flag=0;
    stack<int> st1;
    for(int i=1;i<=m*n;i++)
        {
            //cout<<i<<"begin";
        if(i!=min1)
        st1.push(i);
        else {
            //cout<<i<<endl;
        flag++;
            min1=my[flag];
        }
        }

    for(int i=n-1;i>=0&&!st1.empty();i--)
    {
        //cout<<st1.top()<<','<<my[i]<<endl;
        if(my[i]>st1.top())
        {win++;
        //cout<<my[i]<<"win"<<endl;
        }
        else{
            st1.pop();
            }
    }
    printf("Case %d: %d\n", k, win);
    }
}
