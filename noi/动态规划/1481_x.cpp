#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int maxn=50005;
typedef long long ll;
ll dp1[maxn],dp2[maxn],s1[maxn],s2[maxn];
ll a[50005];

ll mymax(ll a,ll b)
{

  ll tmp;
  tmp=(a>b)?a:b;
  return tmp;
}
ll f(int num)
{
    ll res=-999999;
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    //for(int i=0;i<num;i++)
    //    cout<<a[i]<<' '<<endl;
    int i=0,j=0,k=0;
    dp1[0]=a[0];
    s1[0]=a[0];
    for(i=1;i<num-1;i++)
    {
        dp1[i]=mymax(dp1[i-1]+a[i],a[i]);
        s1[i]=mymax(dp1[i],s1[i-1]);
    }
    dp2[0]=a[num-1];
    s2[0]=a[num-1];
    for(i=1;i<num-1;i++)
    {
        dp2[i]=mymax(dp2[i-1]+a[num-i-1],a[num-i-1]);
        s2[i]=mymax(dp2[i],s2[i-1]);
    }
    for(i=0;i<num-1;i++)
        res=mymax(res,s1[i]+s2[num-2-i]);
//    memset(dp1,0,sizeof(dp1));
//    memset(dp2,0,sizeof(dp2));
//    memset(s1,0,sizeof(s1));
//    memset(s2,0,sizeof(s2));
//    s1[0]=a[1];s2[n+1]=a[n];
//    for(int i=1;i<=n;i++){
//        dp1[i]=mymax(dp1[i-1]+a[i],a[i]);
//        s1[i]=mymax(s1[i-1],dp1[i]);
//    }
//    for(int i=n;i>=1;i--){
//        dp2[i]=mymax(dp2[i+1]+a[i],a[i]);
//        s2[i]=mymax(s2[i+1],dp2[i]);
//    }
//    for(int i=2;i<=n;i++){
//        res=mymax(res,s1[i-1]+s2[i]);
//    }
//    return res;
}
int main()
{
    int cishu,changdu;
    cin>>cishu;
    int i=0,j=0,r=0;
    ll re;
    while(cishu--){
    cin.get();
    cin>>changdu;
    //scanf("%d",&changdu);
    for(i=0;i<changdu;i++)
        cin>>a[i];
    //scanf("%d",&a[i]);
    re=f(changdu);
    cout<<re<<endl;
    }
    return 0;

}
int main()
{
	ll a,b;
	cin>>a>>b;
	cout<<mymax(a,b);
 } 
