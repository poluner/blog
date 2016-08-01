[题意：给你n个棍子，棍子有两个属性l和w，开启机器加工这些棍子，如果满足l1<=l2且w1<=w2，加工完棍子1之后便可以加工棍子2，否则要再次启动机器，问最少要启动几次？](http://poj.org/problem?id=1065)

题意等价于：给出若干个偏序，求出这样一个集合的大小，该集合中任意两个偏序都不可比较。

分析：如果将棍子按照其中一个属性升序（属性值相同就按另一属性值升序），那么就是求另一个属性的lis链最少条数，要求各条lis链之间不包含相同下标的元素。

进一步分析可得到一个结论: 求最少的最长不降子序列链条数可以转换成，求最长下降子序列长度，因为下降的元素一定不能放在相同的链中，只能放在不同的链中，那么最少的链数便是最长下降子序列的长度。


```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5000;
const int inf=0x3f3f3f3f;

pair<int,int>s[maxn+5];

int n;
int a[maxn+5];
int g[maxn+5];

int lis(){//最长上升子序列模板
    int ans=0;
    memset(g,inf,sizeof(g));
    for(int i=1;i<=n;i++){
        int k=lower_bound(g+1,g+1+n,a[i])-g;
        g[k]=a[i];
        ans=max(ans,k);
    }
    return ans;//返回最长长度
}

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].first>>s[i].second;
        }
        sort(s+1,s+1+n);//按l升序，l相同按w升序
        for(int i=1;i<=n;i++)a[i]=s[i].second;
        reverse(a+1,a+1+n);//原意是求出最长下降子序列，反序之后便是求最长上升子序列，方便套模板
        cout<<lis()<<endl;
    }
}


```
