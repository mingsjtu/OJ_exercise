#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int y,month;
bool isrun(int y)
{
    if(y%4!=0)
        return false;
    else{
        if(y%100==0&&y%400!=0)
        return false;
    }
    return true;
}
void solve(int d,int daym)
{
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    int hang=d;
    int i;
    while(d>0){
        printf("    ");
        d--;
        }
    for(i=1;i<daym;i++)
    {
        printf("%3d ",i);
        hang=(hang+1)%7;
        if(hang==0)
            cout<<endl;
    }
}
int day[12]={31,28,31,30,31,30,31,31,30,31,31,30};
int dayr[12]={31,29,31,30,31,30,31,31,30,31,31,30};
int main()
{
    int i,j,d=1;
    while(cin>>y>>month)
    {
    d=1;
    for(i=1900;i<y;i++)
    {
        bool run=isrun(i);
        if(run)
            d=(d+366)%7;
        else
            d=(d+365)%7;
    }
    if(month!=1){
    if(isrun(y))
    {
    for(j=0;j<month-1;j++)
        {d=(d+dayr[j])%7;
        }
    }
    else
    {
    for(j=0;j<month-1;j++)
        {//cout<<j<<"   "<<d<<endl;
        d=(d+day[j])%7;
        }
    }
    }
    int daym=(isrun(y))?dayr[month-1]:day[month];
    solve(d,daym);
    }

}
