//适用于整数的个数不是很多但又特别大（10^9）的情况，速度很快

vector<int>a;//保存n的所有质因子
void Init(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)a.push_back(i);
        while(n%i==0)n/=i;  //去除掉所有的质因子i
    }
    if(n>1)a.push_back(n);//如果是n是质数的话，n就只有一个质因子n
}
