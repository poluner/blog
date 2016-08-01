int ChinaRemainder(){
    int M=1;
    for(int i=1;i<=n;i++){
        M*=m[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        extend(M/m[i],m[i]);//扩展欧几里得算法求逆元
        ans=(ans+a[i]*M/m[i]*x)%M;
    }
    return (ans+M)%M;//ans可能为负
}
