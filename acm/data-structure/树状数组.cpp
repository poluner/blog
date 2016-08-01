const int maxn=1000;

int a[maxn+5];
int c[maxn+5];
int n;

int lowbit(int x){
    return x&(-x);
}

void add(int x,int d){//将a[x]增加d,修改就往右
    while(x<=n){
        c[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x){//前缀和，询问就往左
    int ans=0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void init(){//初始化c数组
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
        add(i,a[i]);
}
