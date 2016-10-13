首先**升序排序**将所有点按x升序（x相同按y升序），**删除重复点**后得到序列p1,p2...，然后将p1和p2放到凸包中。
从p3开始，当新点在凸包“前进”方向的左边（叉积为正）时继续，**否则（叉积为负或0）依次删除最近加入到凸包的点**，直到新点在左边。  
从左到右做一次之后得到的是“下凸包”，然后从右向左做一次得到“上凸包”，合起来就是完整的凸包。复杂度O(nlogn)。  

```
template<typename T>//使用模板，这样待计算的点可以放在数组也可以放在vector中
vector<point> ch(T first,T last){//凸包模板
    vector<point>p(first,last);
    sort(p.begin(),p.end());//排序
    p.resize(unique(p.begin(),p.end())-p.begin());//去重
    if(p.size()<3)return p;//不是多边形就返回点集，否则会出现除0错误
    
    vector<point>v;
    for(int i=0;i<p.size();i++){//其实p[0]不必计算，直接加入凸包即可，这里统一在了一起
        while(v.size()>=2&&(v.back()-v[v.size()-2]).cross(p[i]-v.back())<=0)v.pop_back();
        v.push_back(p[i]);
    }

    int k=v.size();
    for(int i=p.size()-2;i>=0;i--){//凸包首次加的点(这里是p[n-1])不必计算，其他点(包括p[0])都要计算
        while(v.size()>=k+1&&(v.back()-v[v.size()-2]).cross(p[i]-v.back())<=0)v.pop_back();
        v.push_back(p[i]);
    }
    v.pop_back();//点p[0]加了2遍，所以要去掉
    return v;
}
```
point的定义和主函数如下：
```
#define vct point
const double eps=1e-8;

int dcmp(double d){
    if(fabs(d)<eps)return 0;
    return d<0?-1:1;
}

struct point{
    double x,y;
    void read(){cin>>x>>y;}
    void write(){cout<<x<<ends<<y<<endl;}
    bool operator<(const point b)const{//sort排序定义小于
        if(dcmp(x-b.x))return x<b.x;
        return dcmp(y-b.y)<0;
    }
    bool operator==(const point b)const{return dcmp(x-b.x)==0&&dcmp(y-b.y)==0;}//unique判重需要定义等于
    vct operator-(vct b){return {x-b.x,y-b.y};}
    double cross(vct b){return x*b.y-y*b.x;}
};

int main(){
    point p[100];
    int n;cin>>n;
    for(int i=0;i<n;i++)p[i].read();

    vector<point>v=ch(p,p+n);
    for(int i=0;i<v.size();i++)v[i].write();
}
```
[借用某大神的图来直观描述这个过程：](http://www.cnblogs.com/Booble/archive/2011/03/10/1980089.html)  
![](http://pic002.cnblogs.com/images/2011/139826/2011031018085630.png)  

![](http://pic002.cnblogs.com/images/2011/139826/2011031018193031.png)  

![](http://pic002.cnblogs.com/images/2011/139826/2011031018230049.png)

[uva10652包装木板](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1593)  
题意：有n个矩形木板，需要用一个面积尽量小的凸多边形把它们包起来，求木板占整个包装面积的百分比。  
分析：将所有点做一遍凸包即可，这里另外给出多边形面积模板：  
```
template<typename T>
double area(T first,T last){
    double ans=0;
    for(T i=first+1;i+1<last;i++)ans+=(*i-*first).cross(*(i+1)-*first);
    return ans/2;
}
```
主程序如下：
```
const double pi=atan2(0,-1);
const int maxn=600*4;

point p[maxn+5];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        double sum=0;
        int n;scanf("%d",&n);
        for(int i=1;i<=n*4;i+=4){
            point o;
            double w,h,j;

            o.read();
            scanf("%lf%lf%lf",&w,&h,&j);
            j=-(j*pi/180);

            p[i]=o+vct{w/2,h/2}.rot(j);
            p[i+1]=o+vct{w/2,-h/2}.rot(j);
            p[i+2]=o+vct{-w/2,h/2}.rot(j);
            p[i+3]=o+vct{-w/2,-h/2}.rot(j);

            sum+=w*h;
        }
        vector<point>v=ch(p+1,p+1+n*4);
        printf("%.1f %%\n",sum*100/area(v.begin(),v.end()));
    }
}
```

[uva11168点到直线最短距离和](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2109)  
题意：给出平面上10000个点，找一条直线使所有点在直线同侧（也可以在直线上），且到直线的距离之和最小。  
分析：这条直线一定是凸包的一个边，怎么确定是哪条边呢？  
直线一般方程为：Ax+By+C=0，则点<img src="http://chart.apis.google.com/chart?cht=tx&chl=(%20x_%7B0%7D%2C%20y_%7B0%7D)">到直线的距离为：  
<img src="http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B%7CA%20x_%7B0%7D%2BB%20y_%7B0%7D%2BC%7C%7D%7B%20%5Csqrt%7B%20A%5E%7B2%7D%2B%20B%5E%7B2%7D%7D%20%7D%20">  
由于所有点都在Ax+By+C=0同侧，所以<img src="http://chart.apis.google.com/chart?cht=tx&chl=A%20x_%7B0%7D%2BB%20y_%7B0%7D%2BC">的正负号相同，这样预处理所有点x坐标和y坐标之和，然后枚举凸包的边即可求出最小距离和。 

两点<img src="http://chart.apis.google.com/chart?cht=tx&chl=(x_%7B1%7D%2Cy_%7B1%7D)">，<img src="http://chart.apis.google.com/chart?cht=tx&chl=(x_%7B2%7D%2Cy_%7B2%7D)">所在的直线  
<img src="http://chart.apis.google.com/chart?cht=tx&chl=A%3Dy_%7B1%7D-y_%7B2%7D%0A">  
<img src="http://chart.apis.google.com/chart?cht=tx&chl=B%3Dx_%7B2%7D-x_%7B1%7D%0A">  
<img src="http://chart.apis.google.com/chart?cht=tx&chl=C%3Dx_%7B1%7Dy_%7B2%7D-x_%7B2%7Dy_%7B1%7D%0A">  

主程序如下：  
```
const double eps=1e-5;
const double inf=1e9;
const int maxn=10000;

point p[maxn+5];

int main(){
    int T;scanf("%d",&T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: ",t);
        int n;scanf("%d",&n);
        double sx=0,sy=0;
        for(int i=1;i<=n;i++){
            p[i].read();
            sx+=p[i].x;
            sy+=p[i].y;
        }

        if(n==1||n==2){
            puts("0.000");
            continue;
        }

        double ans=inf;

        vector<point>v=ch(p+1,p+1+n);

        v.push_back(v.front());//将第一个点加进去，因为第一个点和最后一个点也构成一个直线
        for(int i=1;i<v.size();i++){
            double A=v[i-1].y-v[i].y;
            double B=v[i].x-v[i-1].x;
            double C=v[i-1].x*v[i].y-v[i].x*v[i-1].y;

            double sd=fabs((A*sx+B*sy+C*n)/sqrt(A*A+B*B));
            ans=min(ans,sd);
        }
        printf("%.3f\n",ans/n);
    }
}
```
