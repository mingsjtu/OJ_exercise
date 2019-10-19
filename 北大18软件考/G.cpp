#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdio.h>


using namespace std;
struct edge
{
    int u;
    int v;//qidian,zhongdian
    int leng;//changdu
}e[1000000];
bool cmp(edge &e1,edge &e2)
{
    return e1.leng<e2.leng;
}

int main()
{
    int i=0,j=0,m,n,u1,v1,l1;//n ge dian,m ge bian
    int bianshu=0;//边的数量
    bool lian[60];
    //memset(bian,0x3f3f3f3f,sizeof(bian));
    while(1)
    {
        bool flag=1;
        memset(lian,0,sizeof(lian));
        int zongchang=0;
        bianshu=0;
        cin>>n;
        if(n==0)
        break;
        cin>>m;
        if(m<n-1)
            {
            cout<<0<<endl;
            continue;}
        for(i=0;i<n;i++)
        {
            lian[i]=1;//没有被接入
        }
        edge tmp;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u1,&v1,&l1);
            tmp={u1,v1,l1};
            e[i]=tmp;
        }
        sort(e,e+m,cmp);
        //cout<<edgeq.size()<<endl;
        int i=0;
        while(bianshu<n-1)
        {
            if(i>m-1)
            {flag=0;cout<<0<<endl;break;}
            tmp=e[i];
            int bianhaou= tmp.u;
            int bianhaov=tmp.v;
            //cout<<bianhaou<<bianhaov<<endl;
            if(!(lian[bianhaou-1]==0&&lian[bianhaov-1]==0))
            {
            //cout<<<<endl;
            lian[bianhaou-1]=0;
            lian[bianhaov-1]=0;
            zongchang+=tmp.leng;
            bianshu++;
            //cout<<bianshu<<endl;
            }
            i++;
        }
        //cout<<flag;
        if(flag)
        {cout<<zongchang<<endl;}

    }

}
