[题意：在平面坐标的第一象限给出n（2<=n<=200）个点的坐标，一只青蛙要从起点出发跳到终点（途中可以经过任意点），青蛙的落脚点只能在给出的n个点中，问青蛙的跳跃能力最少是多长？](http://poj.org/problem?id=2253)

分析过程和[dijkstra](https://github.com/poluner/blog/blob/master/acm/graph-theory/%E5%8D%95%E6%BA%90%E6%9C%80%E7%9F%AD%E8%B7%AF%EF%BC%8C%E8%BF%AA%E6%9D%B0%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95.md)的过程几乎一摸一样，设d[i]表示从起点到i的所需最短距离，w[i][j]表示点i和j的欧拉距离。

步骤：
 1. 设点i未访问，用最优的点cur更新d[i]，更新公式为d[i]=min(d[i],max(d[cur],w[i][cur]))。
 2. 在所有未访问的点i中找出最小的d，然后将该点设为访问。

复杂度O(n^2)的代码：
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
        if(d[i]<mind){
            mind=d[i];
            mini=i;
        }
    }
    return mini;
}

void update(int cur){
    for(int i=1;i<=n;i++)if(vis[i]==false){//用最优点cur去更新未访问的点
        d[i]=min(d[i],max(d[cur],w[i][cur]));
    }
}

void dj(int cur){
    memset(vis,false,sizeof(vis));
    fill(d+1,d+1+n,inf);
    d[cur]=0;
    while((cur=find())!=-1){
        vis[cur]=true;
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
