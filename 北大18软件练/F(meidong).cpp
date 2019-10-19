#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=1e4+5,V=105;
int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}
struct edge{
    int v,ne,w;
}e[M<<1];
int h[N],cnt=0;
void ins(int u,int v,int w){
    cnt++;
    e[cnt].v=v;e[cnt].w=w;e[cnt].ne=h[u];h[u]=cnt;
    cnt++;
    e[cnt].v=u;e[cnt].w=w;e[cnt].ne=h[v];h[v]=cnt;
}
int n,m,Q,u,v,w,p[N],c,st,ed;

struct hn{
    int u,d,f;//起点，距离，终点
    bool operator <(const hn &rhs)const{return d>rhs.d;}
    hn(int a=0,int b=0,int c=0):u(a),d(b),f(c){}
};
int d[N][V];
bool done[N][V];//
void bfs(int c,int st,int ed){
    memset(d,127,sizeof(d));
    memset(done,0,sizeof(done));
    priority_queue<hn> q;
    q.push(hn(st,0,0));
    d[st][0]=0;

    while(!q.empty()){
        hn x=q.top();q.pop();
        int u=x.u,f=x.f,cost=x.d;//printf("bfs %d %d\n",u,f);
        //if(done[u][f]) continue;
        done[u][f]=1;
        if(u==ed){printf("%d\n",cost);return;}//到终点了

        if(f+1<=c&&!done[u][f+1]&&d[u][f]+p[u]<d[u][f+1]){
            d[u][f+1]=d[u][f]+p[u];
            q.push(hn(u,d[u][f+1],f+1));
        }
        for(int i=h[u];i;i=e[i].ne){
            int v=e[i].v,w=e[i].w;
            if(f>=w&&!done[v][f-w]&&d[v][f-w]>cost){
                d[v][f-w]=cost;
                q.push(hn(v,cost,f-w));
            }
        }
    }
    printf("impossible\n");
}

int main(){
    n=read();m=read();
    for(int i=0;i<n;i++) p[i]=read();
    for(int i=1;i<=m;i++){
        u=read();v=read();w=read();
        ins(u,v,w);
    }
    Q=read();
    for(int i=1;i<=Q;i++){
        c=read();st=read();ed=read();
        bfs(c,st,ed);
    }
}
