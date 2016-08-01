#include<iostream>
#include<map>
using namespace std;

map<int,map<int,int> >a;

int main(){
    a[1][1]=1;
    a[1][2]=2;
    a[2][1]=3;

    int cnt=0;
    for(map<int,map<int,int> >::iterator i=a.begin();i!=a.end();i++){
        cnt+=(i->second).size();
    }
    cout<<cnt<<endl;//获取元素个数

    for(map<int,map<int,int> >::iterator i=a.begin();i!=a.end();i++){
        for(map<int,int>::iterator j=(i->second).begin();j!=(i->second).end();j++){
            cout<<j->second<<ends;
        }
        cout<<endl;
    }

    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            cout<<a[i][j]<<ends;
        }
        cout<<endl;
    }
}
