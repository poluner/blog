[见Wikipedia对Baby-step giant-step的解释](https://en.wikipedia.org/wiki/Baby-step_giant-step)  
[这篇讲的不错](http://blog.csdn.net/acm_cxlove/article/details/7832197)  

关于x的方程<img src="http://latex.codecogs.com/svg.latex?a^x\%n=b">，求最小的x.  
设<img src="http://latex.codecogs.com/svg.latex?m=\left%20\lceil%20\sqrt{n}%20\right%20\rceil">  
设<img src="http://latex.codecogs.com/svg.latex?i,j\in%20[0,m)">  
那么x=i*m+j，求出i,j即可  原公式可以变形为  

<img src="http://latex.codecogs.com/svg.latex?a^j=b*(a^{-1})^{m*i}">  

所以O(m)预处理a^j，用哈希表保存映射关系hash[a^j]=j，然后O(m)遍历i，判断哈希表中是否存在a^j，若存在，答案便是x=i*m+j  

**<img src="http://latex.codecogs.com/svg.latex?a^{-1}">怎么求呢？**  
情况一：a和n互质，<img src="http://latex.codecogs.com/svg.latex?a^{-1}">便是a在模n下的逆元  
情况二：a和n不互质，<img src="http://latex.codecogs.com/svg.latex?a^x\%n=b">可以表示成
<img src="http://latex.codecogs.com/svg.latex?a^x*u+n*v=b">  学过扩展欧几里得的便知道仅当gcd(a,n)|b情况下才有整数解(u,v)；等式两边同时除掉g=gcd(a,n)得到  

<img src="http://latex.codecogs.com/svg.latex?\frac{a}{g}*a^{x-1}*u+\frac{n}{g}*v=\frac{b}{g}">  

等价于：  

<img src="http://latex.codecogs.com/svg.latex?\frac{a}{g}*a^{x-1}\%(\frac{n}{g})=\frac{b}{g}">  

循环除掉gcd直到a与n互质，将a的幂前面的系数以及除的次数保存下来，接下来就按照情况一解出x  
#注意这里有bug，按照<img src="http://latex.codecogs.com/svg.latex?c*a^x\%n=b">解出的x必定大于系数c，但是对于原式来说x是可以小于系数的，考虑到消因子的时候最小除2，所以max(x)=logn，因此先看[0,logn]中是否有满足的x  
##[poj3243情况二](http://poj.org/problem?id=3243)  
哈希表比map快了太多。。。。
```
#include<cstdio>
#include<map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

LL pow(LL a,LL n,LL p){
    if(n==0)return 1;
    if(n&1)return a*pow(a,n-1,p)%p;
    LL t=pow(a,n>>1,p);
    return t*t%p;
}

int gcd(int a,int b,int &x,int &y){
    if(b==0)x=1,y=0;
    else gcd(b,a%b,y,x),y-=x*(a/b);
}

int inv(int a,int p){
    int x,y;
    gcd(a,p,x,y);
    return (x%p+p)%p;
}

const int maxv=1e5;
int val[maxv+5];
int key[maxv+5];

int find(int v){
    int i=v%maxv;
    while(true){
        if(val[i]==-1||val[i]==v)return i;
        i=(i+1)%maxv;
    }
}

int bsgs(int c,int a,int b,int p){//方程c*a^x=b(mod p)求x，其中a和p互质
    memset(val,-1,sizeof val);

    int m=ceil(sqrt((double)p));
    LL e=c;//幂
    for(int j=0;j<m;j++){
        int id=find(e);
        if(val[id]==-1)val[id]=e,key[id]=j;
        e=e*a%p;
    }

    LL invam=pow(inv(a,p),m,p);//a^(-m)
    e=1;
    for(LL i=0;i<m;i++){
        LL aj=b*e%p;
        int id=find(aj);
        if(val[id]!=-1)return i*m+key[id];
        e=e*invam%p;
    }
    return -1;
}

int bsgs(int a,int b,int p){//求a^x=b(mod p)不要求a和p互质

    int maxx=log(p)/log(2);
    LL e=1;
    for(int i=0;i<=maxx;i++){
        if(e==b)return i;
        e=e*a%p;
    }
    
    LL c=1;
    int cnt=0;
    int g;
    while((g=__gcd(a,p))>1){
        if(b%g)return -1;
        c=a/g*c%p;
        p/=g;
        b/=g;
        cnt++;
    }

    int x=bsgs(c,a,b,p);
    if(x==-1)return -1;
    return x+cnt;
}

int main(){
    int x,z,k;
    while(~scanf("%d%d%d",&x,&z,&k)&&(x||z||k)){
        int y=bsgs(x,k%z,z);
        if(y==-1)puts("No Solution");
        else printf("%d\n",y);
    }
}
```
##[poj2417属于情况一](http://poj.org/problem?id=2417)
