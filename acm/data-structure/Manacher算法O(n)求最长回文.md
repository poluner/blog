[证明见此处](http://www.cnblogs.com/biyeymyhjob/archive/2012/10/04/2711527.html)

[51nod1089最长回文子串 V2（Manacher算法）](http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1089)
```
#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;

int p[maxn*2+10];

int manacher(string &s){
    memset(p,0,sizeof(p));
    int id=0,mx=0;
    for(int i=0;i<s.size();i++){
        p[i]=mx>i?min(p[2*id-i],mx-i):1;

        while(i-p[i]>=0&&i+p[i]<=s.size()&&s[i-p[i]]==s[i+p[i]])p[i]++;

        if(mx<i+p[i])mx=i+p[i],id=i;
    }

    //寻找长回文的中心
    int Max=0,Maxi=0;
    for(int i=0;i<s.size();i++){
        if(Max<p[i])Max=p[i],Maxi=i;
    }

    //根据最长回文开头是否是#来算出长度
    int b=Maxi-Max+1;
    int e=Maxi+Max-1;
    return s[b]=='#'?(e-b)/2:(e-b)/2+1;

//    for(int i=b;i<=e;i++){//遍历一遍输出
//        if(s[i]!='#')cout<<s[i];
//    }
//    cout<<endl;
}

int main(){
    string s,ts;
    cin>>ts;
    s+=ts[0];
    for(int i=1;i<ts.size();i++){
        s+='#';        //不要写成s=s+'#'+ts[i],会超时
        s+=ts[i];
    }
    cout<<manacher(s);
}

```
