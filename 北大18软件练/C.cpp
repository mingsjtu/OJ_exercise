#include<iostream>
using namespace std;
int main()
{
    int **map1;
    int n,m,i=0,j=0,route=0;
    int shang=0,xia=0,zuo=0,you=0;
    cin>>n>>m;
    map1=new int*[n+2];
    for(int i=0;i<=n+1;i++)
        map1[i]= new int [m+2];

        for(i=1;i<=n;i++)
        {for(j=1;j<=m;j++)
           cin>>map1[i][j];}

        for(i=0;i<n+2;i++)
            {map1[i][0]=0;
            map1[i][m+1]=0;
            }
        for(j=0;j<m+2;j++)
        {
            map1[0][j]=0;
            map1[n+1][j]=0;
        }

        for(i=1;i<=n;i++)
        {
        for(j=1;j<=m;j++){
            //cout<<"map1"<<map1[i][j]<<endl;
        if(map1[i][j]==0){
            continue;}
            route+=4-map1[i-1][j]-map1[i+1][j]-map1[i][j+1]-map1[i][j-1];
            }
        }
            cout<<route;


}
