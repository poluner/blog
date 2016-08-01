[题意：一个n（n<=20）个结点的无向图，要求打印从结点1到结点k的所有路径](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=144)

解法：简单的dfs，但是会超时，因为有些结点不能到达k，所以搜索这些结点完全是多余的，可以用并查集将能到达k的结点放入一个集合，搜索这些结点就可以了。

```
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int k;
int g[20+5][20+5];//邻接矩阵
int vis[20+5];
int path[20+5];//记录路径，方便打印
int cnt;

int p[20+5];
int Find(int x){
    if(p[x]==x)return x;
    return p[x]=Find(p[x]);
}

bool read(){
    if(scanf("%d",&k)==EOF)return 0;
    for(int i=1;i<=20;i++)p[i]=i;
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    int x,y;
    while(scanf("%d%d",&x,&y),x||y){
        g[x][y]=g[y][x]=1;

        p[Find(x)]=Find(y);//可达点放入同一个集合
    }
    return 1;
}

void dfs(int cur,int dep){
    if(cur==k){
        cnt++;
        for(int i=1;i<=dep;i++){
            if(i!=1)printf(" ");
            printf("%d",path[i]);
        }
        puts("");
        return;
    }
    for(int i=1;i<=20;i++){
        if(g[cur][i]&&vis[i]==0){
            vis[i]=1;
            path[dep+1]=i;
            dfs(i,dep+1);
            vis[i]=0;
        }
    }
}

int main(){
    int t=1;
    while(read()){
        printf("CASE %d:\n",t++);

        vis[1]=1;
        for(int i=1;i<=20;i++){//不能到达起火点的节点在搜索前就要先排除，否则搜索会超时
            if(Find(i)!=Find(k))vis[i]=1;//标记已访问即可
        }

        cnt=0;
        path[1]=1;
        dfs(1,1);
        printf("There are %d routes from the firestation to streetcorner %d.\n",cnt,k);
    }
}


```

