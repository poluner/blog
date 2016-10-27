[loj1289LCM from 1 to n](http://lightoj.com/volume_showproblem.php?problem=1289)  
lcm(a,b)就是a和b的素因子取最高次幂的乘积，所以求lcm(1,2,...,n)就是找素数的最高次幂的乘积。  
有两个地方要注意：  
 1. 1e8的bool数组开不下，要用bitset才行。  
 2. 直接找会超时，要先处理素数前缀和
 
另外用了vector也会mle
```
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int ui;
const int maxn=1e8;
const int maxps=5761455;

int ps=0;
int p[maxps+5];
ui sum[maxps+5];
bitset<maxn+5>vis;
void getp() {
    vis.reset();
    for(int i=2; i<=maxn; i++) {
        if(vis[i]==false)p[ps++]=i;
        for(int j=0; j<ps&&i*p[j]<=maxn; j++) {
            vis[i*p[j]]=true;
            if(i%p[j]==0)break;
        }
    }
    sum[0]=p[0];
    for(int i=1; i<ps; i++)sum[i]=sum[i-1]*p[i];
}

LL find(LL a,LL n) {
    LL ans=a;
    while(ans*a<=n)ans*=a;
    return ans;
}

ui lcm(int n) {
    ui ans = sum[upper_bound (p,p+ps, n)-p-1];//前缀乘积
    for (int i=0; i<ps && p[i]*p[i] <= n; i++) {//这个p[i]*p[i]<=n使得不超时
        ans*=find(p[i],n)/p[i];
    }
    return ans;
}

int main() {
    getp();
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++) {
        int n;
        scanf("%d",&n);
        printf("Case %d: %u\n",t,lcm(n));
    }
}
```
如果lcm函数写成下面这样，不用前缀乘积，就会超时，真是醉了
```
ui lcm(int n){
    ui ans=1;
    for(int i=0;i<ps&&p[i]<=n;i++){//只用一个p[i]<=n超时
        ans*=find(p[i],n);
    }
    return ans;
}
```
