#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
//char a[202],b[202];
struct big
{
    int len;
    int digit[202];
    void init()
    {
        len=0;
        memset(digit,0,sizeof(digit));
    }
    big operator+(const big &b)
    {
        int tmp;
        big res;
        res.init();
        res.len=(len>b.len)?len:b.len;
        int i,j,carry=0;
        for(i=0;i<res.len;i++)
        {
            tmp=carry+digit[i]+b.digit[i];
            res.digit[i]=tmp%10;
            carry=tmp/10;
        }
        if(carry!=0)
        {
            res.len=res.len+1;
            res.digit[res.len-1]=carry;
        }
        return res;
    }
    big multi(const int b,int w)//b ,weight=w
    {
        int carry=0,tmp,i,j;
        big res;
        res.init();
        res.len=len+w;
        for(i=0;i<w;i++)
            res.digit[i]=0;
        for(i=0;i<len;i++)
        {
            tmp=digit[i]*b+carry;
            res.digit[i+w]=tmp%10;
            carry=tmp/10;
        }
        if(carry!=0)
        {
            res.digit[res.len]=carry;
            res.len=res.len+1;
        }
        return res;
    }
    void dup(const big &b)
    {
        big res;
        len=b.len;
        for(int i=0;i<b.len;i++)
            digit[i]=b.digit[i];
    }
    big operator=(const big b)
    {
        big res;
        len=b.len;
        for(int i=0;i<b.len;i++)
            digit[i]=b.digit[i];
    }
    big operator*(big &b)
    {
        big res,res1,res2;
        res.init();
        int i,j;
        for(i=0;i<len;i++){
        int tmp=digit[i];
        res1=b.multi(tmp,i);
        cout<<"res1  ";res1.display();
        res2=res;
        cout<<"res2  ";res2.display();
        res=res2+res1;
        }
        return res;
    }
    void display()
    {
        int i=len-1;
        for(;i>=0;i--)
            cout<<digit[i];
        cout<<endl;
    }
};
int main()
{
    big d1,d2,res;
    int i;
    char a1[202],a2[202];
    while(scanf("%s%s",a1,a2))
    {
        d1.len=strlen(a1);
        d2.len=strlen(a2);
        for(i=0;i<strlen(a1);i++)
            d1.digit[d1.len-i-1]=a1[i]-'0';
        for(i=0;i<strlen(a2);i++)
            d2.digit[d2.len-i-1]=a2[i]-'0';
        res.init();
        res=d1*d2;
        res.display();
    }
}
