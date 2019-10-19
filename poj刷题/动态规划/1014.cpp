#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n[6];
int dp[60001];
int t[120];
int m;
int main()
{
    int i,j;
    m=0;
  while(cin>>n[0]>>n[1]>>n[2]>>n[3]>>n[4]>>n[5])
  {
      m++;
      int cnt=0;
      int s=0;
      if(n[0]+n[1]+n[2]+n[3]+n[4]+n[5]==0)
        break;
      for(i=0;i<6;i++)
      {
          s+=n[i]*(i+1);
          if(n[i]==0)
            continue;
        int c=1;
          while(n[i]-c>0)
          {
              t[cnt++]=(i+1)*c;
              n[i]-=c;
              c*=2;
          }
          t[cnt++]=n[i]*(i+1);
      }
      int s2=s/2;
      if(s2*2!=s)
        {
            printf("Collection #%d:\nCan't be divided.\n\n",m);
            continue;}
      memset(dp,0,sizeof(dp));
      for(j=0;j<cnt;j++)
      {
          for(i=s2;i>=t[j];i--)
          {
              dp[i]=max(dp[i],dp[i-t[j]]+t[j]);
          }
      }
      //cout<<dp[s2]<<"   "<<s<<endl;
      if(dp[s2]==s2)
        printf("Collection #%d:\nCan be divided.\n\n",m);
      else
        printf("Collection #%d:\nCan't be divided.\n\n",m);
  }
}
