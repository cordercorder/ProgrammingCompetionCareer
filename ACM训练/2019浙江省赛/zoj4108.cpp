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

char a[10010],b[10010];
int T;
int A,B;

void solve(){
    A=0;
    B=0;
    for(int i=1;a[i]!='\0';i++){
        A=A*10+(int)(a[i]-'0');
        A=A%3;
    }
    for(int i=1;b[i]!='\0';i++){
        B=B*10+(int)(b[i]-'0');
        B=B%3;
    }
    A=(A-1+3)%3;
    bool f1=false,f2=false;
    if(A==1){
        f1=true;
    }
    if(B==1){
        f2=true;
    }
    if(f1!=f2){
        puts("1");
    }
    else{
        puts("0");
    }
}

int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%s %s",a+1,b+1);
        solve();
    }
    return 0;
}
