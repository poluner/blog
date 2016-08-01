#include<cmath>
struct node{
    double dis(node);//两点距离

    //向量操作
    node add(node);//加
    double mul(node);//乘
    node mul(double);//倍
    double abs();//模长
    node unt();//单位化
    node neg();//取反
    double agl(node);//夹角度数
    bool eql(node);//向量相等
    int pal(node);//向量平行（同行，反向）

    double x,y;
};
double node::dis(node a){
    return sqrt(pow(x-a.x,2)+pow(y-a.y,2));
}

node node::add(node a){
    return {x+a.x,y+a.y};
}
double node::mul(node a){
    return x*a.x+y*a.y;
}
node node::mul(double a){
    return {x*a,y*a};
}
node node::neg(){
    return {-x,-y};
}

double node::abs(){
    return sqrt(x*x+y*y);
}
node node::unt(){
    double d=this->abs();
    return {x/d,y/d};
}
double node::agl(node a){
    return acos((x*a.x+y*a.y)/(this->abs()*a.abs()));
}

bool node::eql(node a){
    if(fabs(x-a.x)<1e-6&&fabs(y-a.y)<1e-6)return 1;
    return 0;
}
int node::pal(node a){
    node u1=this->unt();//先单位化
    node u2=a.unt();
    if(u1.eql(u2))return 1;//方向相同
    if(u1.eql(u2.neg()))return -1;//方向相反
    return 0;
}
