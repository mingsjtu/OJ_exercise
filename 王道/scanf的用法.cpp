#include<iostream>
#include<cstdio>

using namespace std;
int main()
{

	char c[100],c1[100];

	///字符串输入不需要&，因为本身数组名就是地址了
	scanf("%[^\n]s",c);//不用[^\n]的话，默认遇到空格也结束
	fflush(stdin);//不清空的话，下次在输入直接读入\n
	scanf("%s",c1);//默认遇到空格也结束
	printf("%s\n", c);
	printf("%s\n",c1);


	///输入数组，回车时结束
	int i=0,j=0;
	char flag;
	long long a[100];
    int d[100],d1[100];
	for(i=0;i<100&&flag!='\n';i++)
    {
        scanf("%d",&a[i]);//或者scanf("%d",&d[i])
        scanf("%c",&flag);//或者cin.get(flag);

    }
    j=i;
    for(i=0;i<j;i++)
        {
            printf("%5d ",a[i]);//打印a[i]
            printf("%d ",&a[i]);//打印a[i]的地址
        }
    ///总结，数组必须一个一个输入&a[i]，但是字符串可以传地址
    ///字符串末尾的\n会被保留在缓冲区，再输入必须清空 fflush(stdin);
    ///char---c， int---d,long long ---l
    ///printf不加&，否则打印地址
    ///所有格式化标志都放在%后面，d前面

	return 0;
}
