//http://poj.org/problem?id=2503
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<char*, int> m1;
char* english[10000];
char eng[15];
char fri[15];

int main()
{
    int n=0;
	while (scanf("%s",eng)!=EOF)
	{
	    if (eng[0] == '\0')
			break;
		scanf("%s",eng);
		cout<<eng<<endl;
		m1[fri] = n;
		english[n]=eng;
		//printf("%s%s\n",english[m1[fri]], fri);
		n++;

		//getchar();

	}
	cout << 1;
	while (scanf("%s",fri))
	{
	    //cout<<strlen(fri)<<endl;
		//printf("%s\n",fri);
		cout<<m1[fri]<<endl;
		printf("%s\n",english[4]);
	}
}
