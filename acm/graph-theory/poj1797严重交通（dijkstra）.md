这题和昨天做的[poj2253 Frogger（用单源最短路dijkstra的思路求解）](https://github.com/poluner/blog/blob/master/acm/graph-theory/poj2253%20Frogger%EF%BC%88%E7%94%A8%E5%8D%95%E6%BA%90%E6%9C%80%E7%9F%AD%E8%B7%AFdijkstra%E7%9A%84%E6%80%9D%E8%B7%AF%E6%B1%82%E8%A7%A3%EF%BC%89.md) 几乎一模一样，只是点的数量范围从200变成了1000，O(n^2)没问题。

**需要注意的一点就是两点不可达则令w=0。**

如果起点和终点重合，那么输出一个不小于1000000的数即可。

```
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1000;

int n;
int d[maxn+5];
int w[maxn+5][maxn+5];

bool vis[maxn+5];

int find(){
    int maxi=-1;
    int maxd=0;
    for(int i=1;i<=n;i++)if(vis[i]==false){
        if(d[i]>maxd){
            maxd=d[i];
            maxi=i;
        }
    }
    return maxi;
}

void update(int cur){
    for(int i=1;i<=n;i++)if(vis[i]==false){
        d[i]=max(d[i],min(d[cur],w[i][cur]));
    }
}

void dj(int cur){
    memset(vis,false,sizeof(vis));
    memset(d,0,sizeof(d));
    d[cur]=inf;
    while((cur=find())!=-1){
        vis[cur]=true;
        update(cur);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int m;
        scanf("%d%d",&n,&m);
        memset(w,0,sizeof(w));
        while(m--){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            w[x][y]=w[y][x]=z;
        }
        printf("Scenario #%d:\n",t);
        dj(1);
        printf("%d\n\n",d[n]);
    }
}
```
