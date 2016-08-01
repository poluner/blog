#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;

char a[maxn+5],b[maxn+5];
int sum[maxn+5][maxn+5];

void lcs(){
    memset(sum,0,sizeof(sum));
    int la=strlen(a+1),lb=strlen(b+1);

    for(int i=1;i<=la;i++){
        for(int j=1;j<=lb;j++){
            if(a[i]==b[j])sum[i][j]=sum[i-1][j-1]+1;
            else sum[i][j]=max(sum[i-1][j],sum[i][j-1]);
        }
    }
}
void output(){//输出
    stack<char>ans;
    int i=strlen(a+1),j=strlen(b+1);
    while(i>=1&&j>=1){
        if(a[i]==b[j])ans.push(a[i]),i--,j--;
        while(sum[i][j]==sum[i-1][j])i--;
        while(sum[i][j]==sum[i][j-1])j--;
    }
    while(!ans.empty()){
        printf("%c",ans.top());
        ans.pop();
    }
    cout<<"\n";
}

int main(){
    scanf("%s%s",a+1,b+1);
    lcs();
    output();
}
