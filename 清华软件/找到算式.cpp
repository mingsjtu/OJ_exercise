#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;
int d,n;
int suanshi[11];//baoliu yunsuanfu +0 *1
int shuzi[11];//baoliu shuzi
stack<int> s1;
int dfs(int d)
{
    int res=99999,res1;
    printf("s1size %d des %d\n",s1.size(),d);
    if(s1.size()==1)
    {
        res1=s1.top();
        printf("this des %d\n",res1);
//        if(res1==d)
//            return d;
//        else{
//            if(res1>d&&res1<res)
//            {
//                res=res1;
//                return res;
//            }
//        }
return res1;
    }
    int con,con1,res2,res3;
    //+
    con=s1.top();
    s1.pop();
    res2=dfs(d-con);
    s1.push(con);
    //*
    con=s1.top();
    s1.pop();
    con1=s1.top();
    s1.pop();
    s1.push(con*con1);
    res3=dfs(d);
    s1.pop();
    s1.push(con1);
    s1.push(con);
    if(res2==d||res3==d)
        return d;
    if(res2>d&&res3>d){
    res=(res2+con>res3)?res3:(res2+con);}
    else res=(res2+con<res3)?res3:(res2+con);
    return res;
}
int main()
{
    cin>>n>>d;
    int i=0;
    for(i=0;i<n;i++)
    {
        cin>>shuzi[i];
        s1.push(shuzi[i]);
    }
    cout<<dfs(d);
}
