首先**升序排序**将所有点按x升序（x相同按y升序），**删除重复点**后得到序列p1,p2...，然后将p1和p2放到凸包中。
从p3开始，当新点在凸包“前进”方向的左边（叉积为正）时继续，**否则（叉积为负或0）依次删除最近加入到凸包的点**，直到新点在左边。  
从左到右做一次之后得到的是“下凸包”，然后从右向左做一次得到“上凸包”，合起来就是完整的凸包。复杂度O(nlogn)。  

凸包模板如下，特意用了**template< typename T >**模板，目的是使点集容器选择更灵活：  
```
template<typename T>//使用模板，这样待计算的点可以放在数组也可以放在vector中

void convexHull(T *first,T *last,vector<point>&v){//凸包模板
    vector<point>p(first,last);
    sort(p.begin(),p.end());//排序
    p.resize(unique(p.begin(),p.end())-p.begin());//去重

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
}
```
point的定义和主函数如下：
```
#include<bits/stdc++.h>
#define vct point
using namespace std;
const double eps=1e-8;

int dcmp(double d){
    if(fabs(d)<eps)return 0;
    return d<0?-1:1;
}

struct point{
    double x,y;

    void read(){
        cin>>x>>y;
    }
    void write(){
        cout<<x<<ends<<y<<endl;
    }

    bool operator<(const point b)const{//sort排序定义小于
        if(dcmp(x-b.x))return x<b.x;
        return dcmp(y-b.y)<0;
    }
    bool operator==(const point b)const{//unique判重需要定义等于
        return dcmp(x-b.x)==0&&dcmp(y-b.y)==0;
    }

    vct operator-(vct b){
        return {x-b.x,y-b.y};
    }

    double cross(vct b){
        return x*b.y-y*b.x;
    }
};

int main(){
    point p[100];
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        p[i].read();
    }
    vector<point>v;
    convexHull(p+1,p+1+n,v);
    for(int i=0;i<v.size();i++){
        v[i].write();
    }
}
```
