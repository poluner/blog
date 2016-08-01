[HDU4135Co-prime](http://acm.hdu.edu.cn/showproblem.php?pid=4135)

题意：求区间[A , B]内与N互质的数的个数

分析：

将问题转换一下，用[1 , B]内与N互质的数的个数减去[1 , A-1]内与N互质的数的个数，现在就变成要求[1 , C]内与N互质的数的个数，这样不好求，但是求与N互质的数的个数（设为num）很简单，那么最后答案就是C-num

如何求与N不互质的数的个数：

比如C=12，N=30

第一步：求出N的所有质因子2，3，5

第二步：[1 , C]内是N的因子的倍数的数肯定与N不互质：
            
            {2，4，6，8，10，12} 有C/2 = 6个
            {3，6，9，12} 有C/3 = 4个
            {5，10} 有C/5 = 2个
注意：不能直接加起来6+4+2 = 12个，因为有的数重复出现了，怎么去掉重复呢？

第三步：使用容斥原理，公式为

             C/2 + C/3 +C/5 
             - C/(2*3) - C/(2*5) - C/(3*5)
             + C/(2*3*5)
              
总结了就是奇数个数加，偶数个数减
第四步：用dfs实现，质因子相互组合符合k个数的排列组合（k=1、2、3……），对于每个k用dfs扫一遍

[那么如何快速求整数N的所有质因子呢？](https://github.com/poluner/blog/blob/master/acm/number-theory/%E6%B1%82%E4%B8%80%E4%B8%AA%E6%95%B4%E6%95%B0%E7%9A%84%E8%B4%A8%E5%9B%A0%E6%95%B0.cpp) 

```
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define LL long long

LL A,B,N,a[1000];
int n;
void Init(){//求出N的所有质因子，方法很像素数筛
    n=0;
    for(int i=2;i*i<=N;i++){
        if(N%i==0)a[++n]=i;
        while(N%i==0)N/=i;
    }
    if(N>1)a[++n]=N;
}

int k;
LL num;
void dfs(LL C,LL sum,int cur,int len){//求[1,C]内k个因子的倍数个数
    if(len>k)return;
    if(len==k){
        if(k%2)num+=C/sum;
        else num-=C/sum;
        return;
    }
    for(int i=cur;i<=n;i++)
        dfs(C,sum*a[i],i+1,len+1);
}

LL solve(LL C){//对每个k用dfs扫一遍
    num=0;
    for(k=1;k<=n;k++)
        dfs(C,1,1,0);
    return num;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%lld%lld%lld",&A,&B,&N);
        Init();
        printf("Case #%d: %lld\n",t,B-A+1-solve(B)+solve(A-1));
    }
    return 0;
}

```

