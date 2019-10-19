//https://www.nowcoder.com/practice/171278d170c64d998ab342b3b40171bb?tpId=40&tqId=21336&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
string str;
int main()
{
	int i;
	
	while (cin>>str)
	{
		reverse(str.begin(), str.end());
		cout << str<<endl;

	}
}