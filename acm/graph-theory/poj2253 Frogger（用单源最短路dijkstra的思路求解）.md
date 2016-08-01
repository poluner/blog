[题意：在平面坐标的第一象限给出n（2<=n<=200）个点的坐标，一只青蛙要从起点出发跳到终点（途中可以经过任意点），青蛙的落脚点只能在给出的n个点中，问青蛙的跳跃能力最少是多长？](http://poj.org/problem?id=2253)

分析过程和[dijkstra](http://blog.csdn.net/daniel_csdn/article/details/51820130)的过程几乎一摸一样，设d[i]表示从起点到i的所需最短距离，w[i][j]表示点i和j的欧拉距离。

步骤：
 1. 设点i未访问，用所有访问的点j更新d[i]，更新公式为d[i]=min(d[i],max(d[j],w[i][j]))。
 2. 在所有未访问的点i中找出最小的d，然后将该点设为访问。

#复杂度O(n^3)的代码：
```
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const double inf=1e9;
const int maxn=200;
typedef pair<double,double> PAIR;
PAIR p[maxn+5];

int n;
double d[maxn+5];
double w[maxn+5][maxn+5];

double dis(PAIR &a,PAIR &b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

bool vis[maxn+5];

int find(){
    int mini=-1;
    double mind=inf;
    for(int i=1;i<=n;i++)if(vis[i]==false){
        for(int j=1;j<=n;j++)if(vis[j]){
            d[i]=min(d[i],max(d[j],w[i][j]));
        }
        if(d[i]<mind){
            mind=d[i];
            mini=i;
        }
    }
    return mini;
}

void dj(int cur){
    memset(vis,false,sizeof(vis));
    fill(d+1,d+1+n,inf),d[cur]=0;
    while((cur=find())!=-1){
        vis[cur]=true;
    }
}


int main(){
    int T=0;
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&p[i].first,&p[i].second);
            for(int j=1;j<=i;j++){
                w[i][j]=w[j][i]=dis(p[i],p[j]);
            }
        }
        dj(1);//求出所有点到起点的最小跳跃能力
        printf("Scenario #%d\n",++T);
        printf("Frog Distance = %.3f\n\n",d[2]);
    }
}

```
#可以用优先队列优化到O(n^2logn)：

 1. 设点i未访问，点j已访问，对所有的点j，将max(d[j],w[i][j]) 放到到pq[i]中，每次取出最小的去更新d[i]即可。
 2. find中更新完d，并且找到最小的d之后，要用它的下标mini去更新所有未访问的点i的pq，更新方程为：pq[i].push(max(d[mini],w[mini][i]))。


```
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const double inf=1e9;
const int maxn=200;
typedef pair<double,double> PAIR;
PAIR p[maxn+5];

int n;
double d[maxn+5];
double w[maxn+5][maxn+5];

double dis(PAIR &a,PAIR &b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

priority_queue<double,vector<double>,greater<double> >pq[maxn+5];

bool vis[maxn+5];

int find(){
    int mini=-1;
    double mind=inf;
    for(int i=1;i<=n;i++)if(vis[i]==false){
        d[i]=min(d[i],pq[i].top());
        if(d[i]<mind){
            mind=d[i];
            mini=i;
        }
    }
    return mini;
}

void update(int cur){
    for(int i=1;i<=n;i++)if(vis[i]==false){
        pq[i].push(max(d[cur],w[cur][i]));
    }
}

void initpq(){
    for(int i=1;i<=n;i++){
        while(!pq[i].empty())pq[i].pop();
        for(int j=1;j<=n;j++){
            pq[i].push(max(d[j],w[i][j]));
        }
    }
}

void dj(int cur){
    memset(vis,false,sizeof(vis));
    fill(d+1,d+1+n,inf),d[cur]=0;
    initpq();
    while((cur=find())!=-1){
        vis[cur]=true;
       //这里不需要加pq[cur].pop()，因为cur标记为访问之后，find中的i不会是cur了
        update(cur);
    }
}


int main(){
    int T=0;
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&p[i].first,&p[i].second);
            for(int j=1;j<=i;j++){
                w[i][j]=w[j][i]=dis(p[i],p[j]);
            }
        }
        dj(1);
        printf("Scenario #%d\n",++T);
        printf("Frog Distance = %.3f\n\n",d[2]);
    }
}

```
