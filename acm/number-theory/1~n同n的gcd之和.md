[51nod1040最大公约数之和](http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1040)  
题意：求
<img src="http://latex.codecogs.com/svg.latex?\sum_{i=1}^{n}gcd(i,n)">
，其中1<=n<=1e9  
分析：同n的gcd肯定是n的因子，因子x对答案贡献的个数是gcd(i,n)=x的个数，两边同除以x得到
<img src="http://latex.codecogs.com/svg.latex?gcd(\frac{i}{x},\frac{n}{x})=1">
，也就是求欧拉
<img src="http://latex.codecogs.com/svg.latex?\varphi({\frac{n}{x}})">的值  
```
#include<bits/stdc++.h>
using namespace std;

int phi(int n){
    int sn=(int)sqrt(n);
    int ans=n;
    for(int i=2;i<=sn;i++)if(n%i==0){
        ans=ans/i*(i-1);
        while(n%i==0)n/=i;
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}

vector<int>f;
void getf(int n){//因子
    int sn=(int)sqrt(n);
    for(int i=1;i<=sn;i++)if(n%i==0){
        f.push_back(i);
        if(i*i!=n)f.push_back(n/i);
    }
}

int main(){
    int n;scanf("%d",&n);
    getf(n);

    long long ans=0;
    for(int i=0;i<f.size();i++)ans+=f[i]*phi(n/f[i]);
    printf("%lld\n",ans);
}
```
