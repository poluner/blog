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
    int n=s.size();
    for(int i=0;i<n;i++){
        p[i]=mx>i?min(p[2*id-i],mx-i):1;

        while(i-p[i]>=0&&i+p[i]<n&&s[i-p[i]]==s[i+p[i]])p[i]++;

        if(mx<i+p[i])mx=i+p[i],id=i;
    }

    //寻找长回文的中心
    int maxp=0,maxi=0;
    for(int i=0;i<n;i++){
        if(maxp<p[i])maxp=p[i],maxi=i;
    }

    return maxp-1;

//    for(int i=b;i<=e;i++){//遍历一遍输出
//        if(s[i]!='#')cout<<s[i];
//    }
//    cout<<endl;
}

int main(){
    string s,ts;
    cin>>ts;
    s+='#';
    for(int i=0;i<ts.size();i++){
        s+=ts[i];
        s+='#';//不要写成s=s+'#'+ts[i],会超时
    }
    cout<<manacher(s);
}
```
更新：
```
#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5;
int p[maxn+5];

string lps(const string& s){

    memset(p,0,sizeof p);
    int id=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i<p[id]+id)p[i]=min(p[2*id-i],p[id]+id-i);
        else p[i]=1;
        while(i+p[i]<n&&i-p[i]>=0&&s[i+p[i]]==s[i-p[i]])p[i]++;
        if(p[i]>p[id])id=i;
    }

    for(int i=0;i<n;i++){
        cout<<p[i]<<ends;
    }
    puts("");
    cout<<id<<ends<<p[id]<<endl;
    string ans;
    for(int i=id-p[id]+1;i<=id+p[id]-1;i++){
        if(s[i]!='#')ans=ans+s[i];
    }
    return ans;

}

int main(){
    string ts="cabab";
    string s="#";
    for(int i=0;i<ts.size();i++){
        s=s+ts[i]+"#";
    }
    for(int i=0;i<s.size();i++)cout<<s[i]<<ends;
    puts("");
    string ans=lps(s);
    cout<<ans<<endl;
}
```
