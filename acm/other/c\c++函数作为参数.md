```
#include<bits/stdc++.h>
using namespace std;

bool f(int a,int b,bool(*cmp)(int,int)){
    return cmp(a,b);
}

bool cmp(int x,int y){return x<y;}

int main(){
    cout<<f(1,2,cmp);
}
```
