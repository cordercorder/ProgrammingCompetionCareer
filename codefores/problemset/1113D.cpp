#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

/*head------[@cordercorder]*/

const int maxn=5e3+10;

char s[maxn];
int len;
char str[maxn];
int cnt;
int num[30];

bool check(){
    bool f=true;
    for(int i=1;i<=len;i++){
        f&=(s[i]==str[i]);
    }
    if(f){
        return false;
    }
    for(int i=1,j=len;i<=j;i++,j--){
        if(str[i]!=str[j])
            return false;
    }
    return true;
}

void solve(){
    len=strlen(s+1);
    for(int i=1;i<=len;i++){
        num[(int)(s[i]-'a')]++;
    }
    for(int i=0;i<26;i++){
        if(num[i]>=(len-1)){
            puts("Impossible");
            return ;
        }
    }
    for(int i=1;i<len;i++){
        cnt=0;
        for(int j=i+1;j<=len;j++){
            str[++cnt]=s[j];
        }
        for(int j=1;j<=i;j++){
            str[++cnt]=s[j];
        }
        if(check()){
            puts("1");
            return ;
        }
    }
    puts("2");
}

int main(void){
    scanf("%s",s+1);
    solve();
    return 0;
}
