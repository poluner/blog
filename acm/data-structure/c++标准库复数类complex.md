c++定义了复数类complex，并重载了+-*/ = == != 也提供了计算幅角的函数。

头文件： #include< complex >

格式：complex<数据类型>对象名(实部,虚部)

```
#include<complex>
#include<iostream>
using namespace std;

int main(){
    complex<double>a(-1,1);
    cout<<a.real()<<ends<<a.imag()<<endl;
    cout<<arg(a)<<endl;//计算幅角[-pi,pi]，及x+yi在平面坐标系上与x轴的夹角
}
```
