[将n(n<=64)个木棒拼接成若干等长的木棒，要求等长的木棒越短越好（设为len）。](http://poj.org/problem?id=1011)

一看就是一个复杂度为O(n!)的dfs，肯定会超时，所以要加上一些剪枝才行。

1. 由于木棒越长越不灵活，所以要优先考虑，因此将木棒降序排序。
2. 搜索中如果当前拼接的木棒总长再接上一根木棒x之后长度为len，这种方案最终不成功，那么比x短的木棒不再考虑。
3. 如果拼接过程中一根都没拼，最终却失败，那么别的木棒不再考虑。
4. 如果木棒x拼接后，最终还是失败，那么和x等长的木棒不再考虑。

```
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=64;

int n;
int a[maxn+5];
bool vis[maxn+5];

bool dfs(int sum,int len,int dep){
    if(sum>len)return false;
    if(dep==n&&sum==len)return true;//全部成功
    if(sum==len)return dfs(0,len,dep);//一根成功

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=true;
        if(dfs(sum+a[i],len,dep+1))return true;//全部成功

        //失败
        vis[i]=false;
        if(sum+a[i]==len||sum==0)return false;//最合适的木棒a[i]都失败，则其他木棒不再考虑
        while(a[i]==a[i+1])i++;//失败则与a[i]相同的木棒不再考虑
    }
    return false;
}

int main(){
    while(scanf("%d",&n),n){
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a+1,a+1+n,greater<int>());//降序排序
        memset(vis,false,sizeof(vis));
        for(int len=a[1];len<=sum;len++){
            if(sum%len==0&&dfs(0,len,0)){
                printf("%d\n",len);
                break;
            }
        }
    }
}

```


