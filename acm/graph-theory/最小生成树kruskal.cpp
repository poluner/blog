#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;//点
const int maxm=maxn*10;//边

struct edge{
    int u,v,w;
};

int n,m;
edge e[maxm+5];
int p[maxn+5];

int find(int x){
    return p[x]==-1?x:p[x]=find(p[x]);
}

bool cmp(const edge &a,const edge &b){//边长升序
    return a.w<b.w;
}

int kruskal(){//返回最小生成树的边长和
    int ans=0;
    memset(p,-1,sizeof(p));
    sort(e+1,e+1+m,cmp);

    for(int i=1,cnt=0;i<=m&&cnt<n-1;i++){
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u==v)continue;//在一个集合就不合并！！！
        p[u]=v;
        ans+=e[i].w;
        cnt++;//当cnt==n-1时就要跳出，因为树节点有n个，边有n-1条
    }
    return ans;
}

int main(){
    cin>>n>>m;//n个点m条边
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    cout<<kruskal();
}
