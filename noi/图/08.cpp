#include<iostream>
using namespace std;
int check(int a,int b)
{
    if(a==0)
    {
        if(b==0)
            return 0;
        if(b==2)
            return 1;
        if(b==5)
            return -1;
    }

        if(a==2)
    {
        if(b==0)
            return -1;
        if(b==2)
            return 0;
        if(b==5)
            return 1;
    }
        if(a==5)
    {
        if(b==0)
            return 1;
        if(b==2)
            return -1;
        if(b==5)
            return 0;
    }
}
int main()
{
    int n1,n2,n3,i=0,n=0;
    int *a,*b;
    cin>>n1>>n2>>n3;
    a= new int [n2];
    b= new int [n3];
    for(i=0;i<n2;i++)
        cin>>a[i];
    for(i=0;i<n3;i++)
        cin>>b[i];
//    int *c1,*c2;
//    c1=new int [n1];
//    c2=new int [n1];
int tmp1,tmp2;
    for(i=0;i<n1;i++)
    {
//        c1[i]=a[i%n1];
//        c2[i]=b[i%n2
        tmp1=a[i%n2];
        tmp2=b[i%n3];
        n+=check(tmp1,tmp2);
        //cout<<"num"<<check(tmp1,tmp2)<<endl;
    }
    char win;
    win=n>0?'A':'B';
    cout<<win;
}
