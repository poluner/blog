const int maxn=1000;
const int maxb=10;//maxb=log2(maxn)

int n;
int a[maxn+5];
int d[maxn+5][maxb+5];

void init(){//初始化d数组
    for(int i=1;i<=n;i++)d[i][0]=a[i];//j为0

    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<(j-1))-1<=n;i++){
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq(int l,int r){//查询区间[l,r]最值
    int k=0;
    while((1<<(k+1))<=r-l+1)k++;//使2^k<=r-l+1的最大k
    return min(d[l][k],d[r-(1<<k)+1][k]);//区间[l,l+2^k]和[r-2^k+1,r]有重叠的部分，以保证完全覆盖区间[l,r]
}
