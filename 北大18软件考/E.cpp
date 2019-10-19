//http://bailian.openjudge.cn/ssxly2018/E/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int cishu,chexiang,m;
    cin>>cishu;
    int i=0,j=0,k=0;
    for(i=0;i<cishu;i++)
    {
        cin>>chexiang;//车厢数，每个火车头最大拉的数
        int *a,*he,**re;//乘客数组,乘客数的和,结果（动态规划）
        a = new int [chexiang];
        he = new int [chexiang];
        re = new int* [chexiang];

        for(j=0;j<chexiang;j++)
            {
            re[j]= new int[3];
            cin>>a[j];
            if(j>=1)
            he[j]=he[j-1]+a[j];
            else he[j]=a[j];
            }
        cin>>m;
        for(j=0;j<chexiang;j++)
        for(k=0;k<3;k++)
            re[j][k]=0;
        for(j=0;j<3;j++)
        {
            for(k=1;k<chexiang;k++)
            {
                int tmp;
                if(k<m)
                    tmp=0;
                else tmp=k-m;
                if(j==0)
                    re[k][j]=max(re[k-1][j],he[k]-he[tmp]);
                else
                re[k][j]=max(re[k-1][j],re[tmp][j-1]+he[k]-he[tmp]);
            }

        }
        cout<<re[chexiang-1][2];



    }
}
