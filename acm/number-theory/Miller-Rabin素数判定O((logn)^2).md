证明见《算法分析与设计——c++语言描述（第2版）》的第232页，写的很详细。

其中用到了[快速幂](https://github.com/poluner/blog/blob/master/acm/number-theory/%E5%BF%AB%E9%80%9F%E5%B9%82.md)来判定是否满足费马小定理，同时判定x*x%n==1的解是否只有x=1和x=n-1，这样Carmichael误判为素数的几率会更小
```
#include<bits/stdc++.h>
using namespace std;

int fast(int a,int n,int p){//就是个快速幂，true则必为合数，false则以高概率为素数
    int ret=1;
    while(n>0){
        if(n%2)ret=ret*a%p;
        n>>=1;
        int x=a;
        a=a*a%p;
        if(a==1&&x!=1&&x!=p-1)return true;
    }
    return ret!=1;
}

bool miller_rabin(int n,int alpha){//判定n是否为素数，将合数误判为素数的概率不超过n^(-alpha)
    for(int i=1;i<=(int)alpha*log(n);i++){
        int a=rand()%(n-1)+1;//随机选取数a，0<a<n
        if(fast(a,n-1,n))return false;//必为合数
    }
    return true;//以高概率为素数
}
int main(){
    cout<<miller_rabin(97,20);
}

```
