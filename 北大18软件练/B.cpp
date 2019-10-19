#include<iostream>
#include<string>
using namespace std;
int main()
{
    char str[1000];
    int i=0,tmp=1;
    char tail;
    int a[26];
    for(int i=0;i<26;i++)
    {
        a[i]=0;
    }
    cin.getline(str,1000);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]<='Z'&&str[i]>='A')
            str[i]=str[i]-'A'+'a';
        if(i==0)
            continue;
        else if (str[i]==str[i-1])
            tmp++;
        else {cout<<'('<<str[i-1]<<','<<tmp<<')';
        tmp=1;
        }
    }
    cout<<'('<<str[i-1]<<','<<tmp<<')';
}
