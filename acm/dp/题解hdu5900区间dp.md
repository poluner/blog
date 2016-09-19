[题意：给了n个pair，如果相邻的两个元素的first不互质就可以将这两个元素取出，并且可以累加其second，求最大累加和，取出一对元素后两旁的元素变成相邻](http://acm.hdu.edu.cn/showproblem.php?pid=5900)  
分析：区间dp，设d(i,j)表示区间[i,j]的所能累加的最大值，那么区间就有两种状态：可以取完和不可全部取完。对于不可取完的情况
就必须至少将区间分成两半，分别取得最大值然后累加，复杂度<img src="http://latex.codecogs.com/svg.latex?O(n^3)">。  
数据：
```
6
3 5 5 2 2 3 
1 1 1 1 1 1
```
输出6
```
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PAIR;
typedef long long LL;
const int maxn=300;

PAIR a[maxn+5];

int n;
bool g[maxn+5][maxn+5];
void getg(){//预处理gcd
    memset(g,false,sizeof g);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(__gcd(a[i].first,a[j].first)!=1)g[i][j]=true;
        }
    }
}

LL sum[maxn+5];//前缀和
LL d[maxn+5][maxn+5];

LL dp(int i,int j){
    if(i>=j)return 0;
    LL &ans=d[i][j];
    if(ans!=-1)return ans;//0是有效状态

    if(g[i][j]&&dp(i+1,j-1)==sum[j-1]-sum[i])return ans=sum[j]-sum[i-1];//该区间可以全部取完
    ans=0;
    for(int k=i;k<=j;k++)ans=max(ans,dp(i,k)+dp(k+1,j));//不能全部取完
    return ans;
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        sum[0]=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i].first);
        for(int i=1;i<=n;i++)scanf("%d",&a[i].second),sum[i]=sum[i-1]+a[i].second;
        getg();

        memset(d,-1,sizeof d);
        printf("%lld\n",dp(1,n));
    }
}
```
