#include<iostream>
#include<math.h>
#include<string>
#include <cstdio>
using namespace std;

int main()
{
    char str1[80],str2[80],str3[80],str4[80];
     int a[26];
     for(int i=0;i<26;i++)
        a[i]=0;
    for(int i=0;i<4;i++)
    {gets(str1);
    for(int j=0;str1[j]!='\0';j++)
    {
        if(str1[j]>='A'&&str1[j]<='Z')
            a[str1[j]-'A']++;
    }
    }
    int max=0;
    for(int i=0;i<26;i++)
        if(max<a[i])
            max=a[i];

    bool flag;
    for(int j=max;j>=0;j--){
            flag=0;

    for(int i=0;i<26;i++){
    if(a[i]>j){
        cout<<"*";
        flag=1;}
    else cout<<' ';
    }
    cout<<endl;
    }
char seed;
for(seed='A';seed<='Z';seed++)
    cout<<seed;
}
