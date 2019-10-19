#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n=0,a[5],i=0,tmp;
    char ch[5];
    for(i=0;i<5;i++)
    {
        cin>>ch[i];
        a[i]=int(ch[i]-'A')+1;
        tmp=pow(double(a[i]),i);
        cout<<ch[i]<<"is"<<tmp<<endl;
        n+=pow(-1,i)*pow(a[i],i);
    }


    cout<<n;
}
