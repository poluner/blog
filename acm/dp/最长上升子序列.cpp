#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
const int inf=0x3f3f3f3f;

int a[maxn+5];
int g[maxn+5];
int d[maxn+5];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    memset(g,inf,sizeof(g));

    for(int i=1;i<=n;i++){
        int k=lower_bound(g+1,g+n+1,a[i])-g;//如果要求最长不降子序列，此处改为upper_bound即可
        g[k]=a[i];
        d[i]=k;
    }

    for(int i=1;i<=n;i++)
        cout<<d[i]<<ends;
}
