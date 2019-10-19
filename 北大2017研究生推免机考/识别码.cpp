#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;
char a[20];
int main()
{
    int tmp,re,xi;
    while(scanf("%s",a))
    {
        xi=1;re=0;
        for(int i=0;i<11;i++)
        {

            if(i!=1&&i!=5)
            {tmp=a[i]-'0';
            //cout<<tmp<<endl;
            //cout<<"xi"<<xi<<endl;
            re+=(tmp*xi);
            xi++;
            }
        }
        re=re%11;
        //cout<<"re"<<re<<endl;
        if(re==a[12]-'0')
            cout<<"Right"<<endl;
        else{
            for(int i=0;i<12;i++)
                cout<<a[i];
            cout<<re<<endl;
        }
    }
}
