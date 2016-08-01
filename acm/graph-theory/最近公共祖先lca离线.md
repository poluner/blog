利用dfs和并查集实现点对的最近公共祖先，首先递归到叶子节点，然后在返回时才确定父子关系，按照这样的顺序确定父子关系之后，最早出现的公共父节点便是最近公共祖先。
```
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
const int maxm=1000;

int lca[maxn+5][maxn+5];
vector<int>nxt[maxn+5];
vector<int>q[maxn+5];
int qx[maxm+5],qy[maxm+5];//保存要查询的点对
int p[maxn+5];//并查集

int find(int x){
    return p[x]==-1?x:p[x]=find(p[x]);
}

void dfs(int cur,int fa){
    for(int i=0;i<nxt[cur].size();i++){
        int x=nxt[cur][i];
        if(x==fa)continue;
        dfs(x,cur);
        p[x]=cur;//递归到叶子节点才开始指定父子关系，按这样的顺序最先出现的公共祖先才是最近公共祖先
    }
    for(int i=0;i<q[cur].size();i++){//确定公共祖先，相同的点对会两次到达这里
        int x=q[cur][i];
        lca[min(cur,x)][max(cur,x)]=find(x);
        //第一次的时候cur被访问，x未访问，这时find(x)的值是无效的，这一遍的有无都无所谓
        //第二次的时候cur和x都被访问且x是在cur之前访问过的，这时候x的最上面的祖先就是最近公共祖先
        cout<<min(cur,x)<<ends<<max(cur,x)<<ends<<find(x)<<endl;//这里输出就能弄懂程序的意思
    }
}

int main(){
    int n,m,x,y;
    cin>>n>>m;//n个点，m个查询
    for(int i=1;i<=n-1;i++){//n-1条边
        cin>>x>>y;
        nxt[x].push_back(y);
        nxt[y].push_back(x);
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        qx[i]=x;
        qy[i]=y;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    memset(p,-1,sizeof(p));//并查集初始化
    dfs(1,-1);
    for(int i=1;i<=m;i++){
        cout<<lca[min(qx[i],qy[i])][max(qx[i],qy[i])]<<endl;
    }
}

```
