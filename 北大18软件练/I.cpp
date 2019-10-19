#include<iostream>
#include<cstring>
#include<stdio.h>
#include <cstdio>
#include<cmath>
using namespace  std;
typedef long long ll;

ll exgcd(ll a, ll b,ll &x,ll &y){ 
if(!b){x=1;y=0;return a;
}
else
	exgcd(b,a%b,y,x);
y-=a/b*x;
return (a*x+b*y); 
 }

int main()
{
    ll a,b,c,k;
    while(1)
    {
        scanf("%I64d%I64d%I64d%I64d",a,c,b,k);
        if(a&&b&&c&&k)
            break;
        ll x0=0,y0=0;
        ll g=exgcd(a,b,x0,y0);
        if(g%(c-a)!=0)
        {
        	cout<<"FOREVER"<<endl;
        	break;
		}
		cout<<1<<endl;
        ll b1=b/g,x;
        x=((x0%b1)+b1)%b1;
        cout<<x<<endl;
         
    }
    return 0;
}
