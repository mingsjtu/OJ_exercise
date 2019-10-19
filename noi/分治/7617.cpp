#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int shu[100001];
int shun[100001];
int main()
{
    int n;
    int tmp;
    int i,j,k,r;
    priority_queue<int> q1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>shu[i];
        q1.push(shu[i]);
    }
    cin>>k;
//    while(n>k)
//    {
//        q1.pop();
//        n--;
//    }
    while(k-->0)
    {
        cout<<q1.top()<<endl;
        q1.pop();
    }
}
