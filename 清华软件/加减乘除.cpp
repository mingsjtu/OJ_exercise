#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int x1,x2,x3,x4,y;
bool mark[4];
stack<int> s;//baocun +-*/
bool dfs(float b)
{
    float a1,a2,aa;
    int l=s.size();
    bool flag[4];
    cout<<"current "<<l<<endl;
    if(l==1)
        {
            cout<<s.top()<<endl;
            return s.top()==b;}
    else{
        //+
        a1=s.top();
        s.pop();
        flag[0]=dfs(b-a1);
    s.push(a1);
    //-
    a1=s.top();
    s.pop();
    flag[1]=dfs(a1+b);
    s.push(a1);
    //*
    a1=s.top();
    s.pop();
    a2=s.top();
    s.pop();
    aa=a1*a2;
    s.push(aa);
    flag[2]=dfs(b);
    s.pop();
    s.push(a2);
    s.push(a1);
    // /
    a1=s.top();
    s.pop();
    a2=s.top();
    s.pop();
    aa=a1/a2;
    s.push(aa);
    flag[3]=dfs(b);
    s.pop();
    s.push(a2);
    s.push(a1);
    // /
    a1=s.top();
    s.pop();
    a2=s.top();
    s.pop();
    aa=a2/a1;
    s.push(aa);
    flag[3]=dfs(b);
    s.pop();
    s.push(a2);
    s.push(a1);
    return flag[0]+flag[1]+flag[2]+flag[3];
    }

}
int main()
{
    while(cin>>x1>>x2>>x3>>x4)
    {
        memset(mark,0,sizeof(mark));
        s.push(x1);
        s.push(x2);
        s.push(x3);
        s.push(x4);
        bool res=dfs(y);
        cout<<res<<endl;
    }
}
