首先用kmp找出所有模式串的位置放在id中（vector类型），然后做dp，dp方程为：

对于第i个位置，如果第j( j < i 中最大的 j )个位置满足

id[i]-id[j]>=son.size()（即模式串在主串中的这两个位置没有重叠部分），

则d[i]=d[i-1]+d[j]；

如果这个j不存在则d[i]=d[i-1]+1。

```
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int maxn=100000;

vector<int>id;

int nxt[maxn+5];
string father,son;

void getnext(){
    nxt[0]=-1;
    int j=0,k=-1;
    while(j<son.size()){
        if(k==-1||son[j]==son[k])nxt[++j]=++k;
        else k=nxt[k];
    }
}
void kmp(){
    getnext();
    int i=0,j=0;
    while(i<(int)father.size()){
        while(i<(int)father.size()&&j<(int)son.size()){//这里一定要将size()强转成int类型，不然就出错了
            if(j==-1||father[i]==son[j])i++,j++;
            else j=nxt[j];
        }
        if(j>=(int)son.size()){
            id.push_back(i-j);//记录模式串在主串中的位置
            j=nxt[j];
        }
    }
}

long long d[maxn+5];

long long dp(){
    if(id.size()==0)return 1;
    d[0]=2;
    for(int i=1;i<id.size();i++){
        int j;
        for(j=i-1;j>=0&&id[i]-id[j]<son.size();j--);
        if(j>=0)d[i]=(d[i-1]+d[j])%mod;//存在j
        else d[i]=(d[i-1]+1)%mod;//不存在j
    }
    return (d[id.size()-1])%mod;
}

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>father>>son;
        id.clear();
        kmp();
        printf("Case #%d: %lld\n",t,dp());
    }
}

```
