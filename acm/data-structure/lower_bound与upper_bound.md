升序序列：  
lower_bound 指向 **>=key 的第一个元素**  
upper_bound 指向 **>key 的第一个元素**  

降序序列:  
lower_bound 指向 **<=key 的第一个元素**  
upper_bound 指向 **<key  的最后一个元素的后一个元素**  

#double类型给定精度如何正确查找
对于数据类型为double的情况下，一般题目都会给定一个精度eps，如何让以上函数根据给定的精度来得到正确的返回值呢？  
由于**元素相差在eps内的被视为相等**，所以做如下更改：  
**升序序列：
lower_bound(key-eps)**  
**降序序列：
lower_bound(key+eps)**  
才能得到正确的返回值，upper_bound没有等于关系，所以不更改。

下面用代码说明：
```
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;//设置精度

int n=1;
double a[]={1e-8,1};

int main(){
    double key=1e-7;
    int i=lower_bound(a,a+n,key)-a;//按照double的精度
    cout<<i<<endl;//按照double的精度,a[0]<key，a[1]>=key，所以输出1
    int j=lower_bound(a,a+n,key-eps)-a;//按照给定的精度eps
    cout<<j;//按照设置的精度eps,a[0]>=key，所以输出0
}
```
#升序如果所有元素都小于key，则两者都返回首地址
因此查询小于key的最大元素下标用upper_bound()-1而不是lower_bound
```
int a[]={1};
cout<<lower_bound(a,a+1,0)-a<<endl;//输出0就错了，1不比0小
cout<<upper_bound(a,a+1,0)-a-1<<endl;//输出-1是正确的，表示不存在元素小于0
```
