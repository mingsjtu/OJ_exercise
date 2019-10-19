#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int num,i=0,j=0;//行数
    int *re,max1=0,jian=0,re1=1,re2=1;//建筑物高度
    cin>>num;

    for(i=0;i<num;i++)
    {
        max1=0;
        cin>>jian;//shuliang
        int *a = new int [jian];
        int *re = new int [jian];
        for(j=0;j<jian;j++)
            {cin>>a[j];
            re[j]=1;
            }
    //condition1
        for(j=0;j<jian;j++)
        {
            for(int k=0;k<j;k++)
            {
                if(a[j]>a[k])
                {
                    //cout<<"+1"<<endl;
                    re[j]=max(re[j],re[k]+1);
                }

            }
        }
        for(j=0;j<jian;j++)
            re1=max(re1,re[j]);
    //condition2
        for(j=0;j<jian;j++)
                {
                re[j]=1;
                }
        for(j=jian-1;j>=0;j--)
        {
            for(int k=jian-1;k>j;k--)
            {
                if(a[j]>a[k])
                {re[j]=max(re[j],re[k]+1);
                //cout<<j<<"+1="<<re[j]<<endl;
                }
            }
            }
            for(j=0;j<jian;j++)
                {re2=max(re2,re[j]);
                }

        cout<<max(re1,re2);
        delete re;
    }
    return 0;


}
