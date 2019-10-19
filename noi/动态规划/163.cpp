#include <iostream>
#include <cstdio>
using namespace std;

const int INF=1e8;
int x[305];
int d[305][35];
int s[305][305];

int main()
{
    //freopen("in.txt","r",stdin);
    int n,p;
    while(~scanf("%d%d",&n,&p))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<i && j<=p;j++)
                d[i][j]=INF;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
                s[i][j]=s[i][j-1]+x[j]-x[(i+j)/2];
            d[i][1]=s[1][i];
        }
        for(int i=2;i<=n;i++)
            for(int j=2;j<=i && j<=p;j++)
                for(int k=j-1;k<i;k++)
                    d[i][j]=min(d[i][j],d[k][j-1]+s[k+1][i]);
        printf("%d\n",d[n][p]);
    }
    return 0;
}
