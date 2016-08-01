#include<bits/stdc++.h>
using namespace std;

int nxt[100];
string father,son;

void getnxt(){
    nxt[0]=-1;
    int j=0,k=-1;
    while(j<son.size()){
        if(k==-1||son[j]==son[k])nxt[++j]=++k;
        else k=nxt[k];
    }
}

int kmp(){
    getnxt();
    int i=0,j=0;
    while(i<(int)father.size()&&j<(int)son.size()){//这里一定要将size()强转成int类型，不然就出错了
        if(j==-1||father[i]==son[j])i++,j++;
        else j=nxt[j];
    }
    if(j<(int)son.size())return -1;
    return i-j;
}
int main(){
    cin>>father>>son;
    cout<<kmp()<<endl;

    cout<<(0<father.size())<<endl;
    cout<<(-1<father.size())<<endl;//居然输出0,-1明明比father.size()小啊！
    cout<<(-1<(int)father.size());//size用int强转一下
}
