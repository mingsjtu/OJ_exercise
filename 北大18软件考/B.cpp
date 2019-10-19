#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main()
{
    int n,cnt=20,max=0,biaohao[500],cnt1=0;
    for(int i=0;i<500;i++)
        biaohao[i]=-1;
    bool flag=0;
    char str[500];
    //char *str1[];
    //str1= new char [n];
    cin>>n>>str;
//    for(int i=1;str[i]!='\0';i++)
//   {
//       cout<<str[i];
//       cnt++;}
//       cout<<cnt;

    for(int i=1;str[i]!='\0';i++)
    {
        //cout<<i;
        cnt=0;
        for(int j=0;j<=i-1;j++)
        {
            flag=1;
            for(int k=0;k<n;k++)
                {
                    if(str[i+k]!=str[j+k])
            {
                //cout<<k<<" ";
                flag=0;
                //break;
            }
            }
            //cout<<i<<j<<"num"<<endl;
            if(flag)
            cnt++;
        }
        //cout<<i<<"is  "<<cnt<<max<<endl;
        if(max<cnt)
        {
            max=cnt;
            for(int f=0;f<cnt1;f++)
                biaohao[f]=-1;
            cnt1=0;
            biaohao[cnt1]=i;
            cnt1++;
        }
        else if(max==cnt&&cnt>0)
        {
            biaohao[cnt1]=i;
            cnt1++;
        }
    }
    if(max==0)
        cout<<"NO"<<endl;
    else {cout<<++max<<endl;
    for(int t=0;t<cnt1;t++){
    for(int k=0;k<n;k++)
        cout<<str[biaohao[t]+k];
        cout<<endl;
    }
    }
}



