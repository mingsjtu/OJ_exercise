#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
char s[26];
char num[26];
int vis[26];
int tmp[5];
int ans[26];
int flag;
int len;
long long target;

bool cmp(int a,int b)
{
    return a>b;//����a>b ;����a<b
}

void dfs(long long n){//������0��ʼ
   if(n>=5){//����5����
   	 if(flag==0&&(tmp[0]-pow(tmp[1],2)+pow(tmp[2],3)-pow(tmp[3],4)+pow(tmp[4],5)==target)){
   	 	  for(int i=0;i<5;i++){
   	 	  	   ans[i]=tmp[i];
   	 	  	   //flag=1;
			  }
			  flag=1;
		}
   }
   else{//����5����
     for(int i=0;i<len;i++){//��5��Ҫ��12������
     	if(vis[i]==0){//���������ÿ�ù�
     		tmp[n]=num[i];
     		vis[i]=1;
     		dfs(n+1);
     		vis[i]=0;
		 }
	 }

   }

}
int main(int argc, char** argv) {


	while(scanf("%lld %s",&target,s)==2){
		if(target==0&&strcmp(s,"END")==0){//�жϽ���
			break;
		}
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
		memset(tmp,0,sizeof(tmp));
		memset(vis,0,sizeof(vis));
		flag=0;
		len=strlen(s);
		for(int i=0;i<len;i++){//���ַ�ת��Ϊ����
			num[i]=s[i]-'A'+1;
		}
		sort(num,num+len,cmp);
		dfs(0);
		if(flag==1){
			for(int i=0;i<5;i++){
			  printf("%c",ans[i]-1+'A')	;
			}
			printf("\n");
		}
		else{
			printf("no solution\n");
		}

	}

	return 0;
}
