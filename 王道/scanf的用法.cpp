#include<iostream>
#include<cstdio>

using namespace std;
int main()
{

	char c[100],c1[100];

	///�ַ������벻��Ҫ&����Ϊ�������������ǵ�ַ��
	scanf("%[^\n]s",c);//����[^\n]�Ļ���Ĭ�������ո�Ҳ����
	fflush(stdin);//����յĻ����´�������ֱ�Ӷ���\n
	scanf("%s",c1);//Ĭ�������ո�Ҳ����
	printf("%s\n", c);
	printf("%s\n",c1);


	///�������飬�س�ʱ����
	int i=0,j=0;
	char flag;
	long long a[100];
    int d[100],d1[100];
	for(i=0;i<100&&flag!='\n';i++)
    {
        scanf("%d",&a[i]);//����scanf("%d",&d[i])
        scanf("%c",&flag);//����cin.get(flag);

    }
    j=i;
    for(i=0;i<j;i++)
        {
            printf("%5d ",a[i]);//��ӡa[i]
            printf("%d ",&a[i]);//��ӡa[i]�ĵ�ַ
        }
    ///�ܽᣬ�������һ��һ������&a[i]�������ַ������Դ���ַ
    ///�ַ���ĩβ��\n�ᱻ�����ڻ������������������� fflush(stdin);
    ///char---c�� int---d,long long ---l
    ///printf����&�������ӡ��ַ
    ///���и�ʽ����־������%���棬dǰ��

	return 0;
}
