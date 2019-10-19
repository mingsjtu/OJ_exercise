#include<iostream>
#include<cstdio>
#include<math.h>
#include<map>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
map<int,int> m1;
vector<int> v1;
bool marked[10000];
int ini,res;
void findprime()
{
    memset(marked,0,sizeof(marked));
    v1.clear();
    int tmp,j;
    for(int i=2;i<10000;i++)
    {
        if(marked[i]==false&&i>=1000)
            v1.push_back(i);
        for(j=i*i;j<10000;j+=i)
        {
            if(!marked[j])
            marked[j]=true;
        }
    }
}
int arr[10000],marked1[10000];
int k=0;
queue<int> q1;
int bfs(int sta)
{
int tmp1,tmp2,i,j;
q1.push(sta);
marked[sta]=1;
arr[sta]=0;
   while(!q1.empty())
   {
        tmp1=q1.front();
        q1.pop();

        for(i=1;i<=9;i+=2)
        {
        tmp2=tmp1/10*10+i;
        if(tmp2==res)
            return arr[tmp1]+1;
        if(marked[tmp2]==0&&marked1[tmp2]==false)
            {
            //cout<<"tmp  "<<tmp1<<endl;
            marked1[tmp2]=true;
            arr[tmp2]=arr[tmp1]+1;
            //arr[k++]=tmp2;
            q1.push(tmp2);
            }
        }
        for(i=0;i<=9;i++)
        {
        tmp2=tmp1/100*100+i*10+tmp1%10;
        if(tmp2==res)
            return arr[tmp1]+1;
        if(marked[tmp2]==0&&marked1[tmp2]==false)
            {
            //cout<<"tmp  "<<tmp1<<endl;
            marked1[tmp2]=true;
            arr[tmp2]=arr[tmp1]+1;
            //arr[k++]=tmp2;
            q1.push(tmp2);
            }
        }
        for(i=0;i<=9;i++)
        {
        tmp2=tmp1/1000*1000+i*100+tmp1%100;
        if(tmp2==res)
            return arr[tmp1]+1;
        if(marked[tmp2]==0&&marked1[tmp2]==false)
            {
            marked1[tmp2]=true;
            arr[tmp2]=arr[tmp1]+1;
            //arr[k++]=tmp2;
            q1.push(tmp2);
            }
        }
        for(i=1;i<=9;i++)
        {
        tmp2=tmp1%1000+i*1000;
        if(tmp2==res)
            return arr[tmp1]+1;
        if(marked[tmp2]==0&&marked1[tmp2]==false)
            {
            //cout<<"tmp  "<<tmp1<<endl;
            marked1[tmp2]=true;
            arr[tmp2]=arr[tmp1]+1;
            //arr[k++]=tmp2;
            q1.push(tmp2);
            }
        }
    }
    return -1;
}
int c;
int main()
{
    int i=0;
    findprime();
cin>>c;
while(c-->0){
cin>>ini>>res;
if(ini==res)
{cout<<0<<endl;
continue;}
memset(marked1,0,sizeof(marked1));
int flag=bfs(ini);
if(flag>0)
    cout<<flag<<endl;
}
}
