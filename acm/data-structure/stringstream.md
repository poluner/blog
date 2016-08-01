头文件

```
#include<sstream>
```
常用于数据转换和分割字符串

```
int n;
string s="10 100 22";
stringstream ss;//或者stringstream ss(s);
ss<<s;
while(ss>>n)//分割并且转换成数
    cout<<n<<ends;

cout<<endl;
ss.clear();//sstream自带缓冲，所以要及时清除缓冲区
s="abc def gh";
ss<<s;
while(ss>>s)//分割串
    cout<<s<<ends;
```
