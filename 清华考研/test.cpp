//https://www.nowcoder.com/practice/0337e32b1e5543a19fa380e36d9343d7?tpId=60&tqId=29473&tPage=1&rp=1&ru=/ta/tsing-kaoyan

#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;
typedef long long ll;
int main()
{
    ll dang,tmp;
    stack<ll> v;
    while(scanf("%lld",&dang))
    {
        while(dang>=2){
        tmp=dang%2;
        dang=dang/2;
		v.push(tmp);
		//cout<<"this"<<tmp<<endl;
		}
		v.push(dang);
        
    while(!v.empty())
    {
        tmp=v.top();
        v.pop();
        printf("%lld",tmp);
    }
        cout<<endl;
    }
    
}
