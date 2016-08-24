半平面其实就是一条有向直线，规定其左边是平面。半平面的交一般是凸多边形，也有可能是开放区域、线、点。  

求半平面交做法其实和求凸包类似，不过凸包用的是栈，而半平面交用的是双端队列，因为直线按极角排序，后面的直线可能“绕过一圈”之后使得最开始加入的
直线失效而被弹出。

算法过程如下：
 1. 将直线按极角升序
 2. 对于每条新线：
  1. 如果最后加入的两条直线交点不在新线左边，弹出最后尾线
  2. 如果最初加入的两条直线交点不在新线左边，弹出最初首线
  3. **如果新线平行于尾线且在其左边，用新线替换掉尾线**，否则添加到队列末尾
 3. **如果最初加入的两条直线的交点不在尾线的左边，则弹出尾线**

模板如下：
```
template<typename T>
vector<point>hpi(T first,T last){
    vector<line>l(first,last);
    sort(l.begin(),l.end());//按极角升序
    deque<line>q; //双端队列

    for(int i=0;i<l.size();i++){
        while(q.size()>=2&&l[i].onleft(q.back().intersection(*(q.end()-2)))==false)q.pop_back();//最后加入的直线的交点不在新线左边
        while(q.size()>=2&&l[i].onleft(q.front().intersection(*(q.begin()+1)))==false)q.pop_front();//最初加入的直线的交点不在新线左边

        if(q.size()&&l[i].parallel(q.back())){//加入了直线且平行
            if(q.back().onleft(l[i].p))*(q.end()-1)=l[i];//如果新线在尾线内侧则替换尾线
        }else q.push_back(l[i]);//没有加入直线或不平行
    }
    while(q.size()>=2&&q.front().onleft(q.back().intersection(*(q.end()-2)))==false)q.pop_back();//头交点在尾线左侧，删除尾线

    if(q.size()<=2)return vector<point>();//不构成半平面，则返回空集
    vector<point>p;
    for(deque<line>::iterator i=q.begin();i+1<q.end();i++)p.push_back(i->intersection(*(i+1)));
    p.push_back(q.front().intersection(q.back()));
    return p;//返回半平面交点
}
```
直线的定义如下：
```
struct line{
    point p;
    vct v;
    double ang;

    line(){}
    line(point p,vct v):p(p),v(v){ang=atan2(v.y,v.x);}

    bool operator<(line b)const{return dcmp(ang-b.ang)<0;}//按极角升序
    bool onleft(point b){return dcmp(v.cross(b-p))>0;}//点b在直线左边，在直线上不算，如果允许半平面是条线段则应算上直线上的点，改>为>=
    point intersection(line b){//与直线b的交点
        double t=b.v.cross(p-b.p)/v.cross(b.v);
        return p+v*t;
    }
    bool parallel(line b){return dcmp(v.cross(b.v))==0;}//平行于直线b
};
```

半平面交可以判断多边形是否存在核：核差不多就是是否存在一点使得该点可以无穿透地直线地到达多边形内的任意一点，比如下图左边的多边形存在核
右边的不存在核。  
![](http://poj.org/images/1474_1.jpg)  

poj上的几个简单的模板题：  
 * [poj3335是否存在核](http://poj.org/problem?id=3335) 其中点是顺时针给出，注意最后半平面的交可能是线，所以在直线定义中onleft要改>为>=
 * [poj1474是否存在核](http://poj.org/problem?id=1474) 完全同上一题。。。
 * [poj1279半平面交的面积](http://poj.org/problem?id=1279) 点也是顺时针给出，得到交的多边形之后直接计算面积即可


[la3890离海最远的点](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1891)  
题意：海上有一个凸n边形小岛，求出岛上离海最远的点，输出它到海的最远距离，凸n边形的点逆时针给出  
分析：可以二分答案，然后解决一个判定问题：是否有离海距离不小于d的点？对于每条边来说，这些点形成一个半平面，如果半平面非空，就有满足题意的点存在，具体做法是收缩多边形，将所有边向内平移，如果平移后半平面交非空，则继续向内平移。

直线的定义中添加平移函数move()：
```
line move(double t){return {p+v.normal()*t,v};}//向左平移距离t
```
主程序如下：
```
const double eps=1e-7;
const int maxn=20000;

line l[maxn+5];
point p[maxn+5];

int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++)p[i].read();
        p[n+1]=p[1];

        double left=0,right=20000;
        while(dcmp(left-right)<0){ /二分
            double mid=(left+right)/2;
            for(int i=1;i<=n;i++)l[i]=line(p[i],p[i+1]-p[i]).move(mid); //多边形向内收缩
            vector<point>poly=hpi(l+1,l+1+n);
            if(poly.size())left=mid;
            else right=mid;
        }
        printf("%f\n",left);
    }
}
```

