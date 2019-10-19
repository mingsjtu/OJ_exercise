#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include <stdio.h>
using namespace std;
class mindui
{
    private:
    int *dui,cap=10000,currentsize=0;
    public:
    mindui(int cap1):cap(10000){
    dui= new int[cap1];
    cap=cap1;
    currentsize=0;
    }
    void insert(int num)
    {
        int hole =++currentsize;
        while(hole/2>0&&num<dui[hole/2])
            {
            dui[hole]=dui[hole/2];
            hole=hole/2;
            }
        dui[hole]=num;
    }
    int chudui()
    {
        int minitem=dui[1];
        dui[1]=dui[currentsize];
        predown(1);
        currentsize--;
        return minitem;
    }
    void predown(int n)
    {
        int child =n*2;
        int tmp=dui[n];
        for(;n*2<currentsize;n=child)
        {
            child=n*2;
        if(child+1<currentsize&&dui[child]>dui[child+1])
            child++;
        if(dui[child]<tmp)
            dui[n]=dui[child];
        else
            break;
        }
        dui[n]=tmp;
    }
};
int main()
{
    int cishu;
    cin>>cishu;
    int i=0,a,b;
    mindui dui1(10000);
    for(i=0;i<cishu;i++)
    {
        cin>>a;
    if(a==1)
    {
        cin>>b;
        dui1.insert(b);
        //cout<<"insert"<<b<<endl;
    }

    else
        cout<<dui1.chudui()<<endl;
    }
    return 0;
}
