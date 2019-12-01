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

const int maxn=1010; 

int n,m;
int a[maxn][maxn];
int ret[maxn];
int r[maxn][maxn],c[maxn][maxn];
int R[maxn][maxn],C[maxn][maxn];

void print(int num[][maxn]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",num[i][j]);
        }
        puts("");
    }
    puts("");
} 

void solve(){
    int cnt,pos;
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=1;j<=m;j++){
            ret[++cnt]=a[i][j];
        }
        sort(ret+1,ret+1+cnt);
        cnt=unique(ret+1,ret+1+cnt)-ret-1;
        for(int j=1;j<=m;j++){
            pos=lower_bound(ret+1,ret+1+cnt,a[i][j])-ret;
            r[i][j]=pos;
            R[i][j]=cnt-pos;
        }
    }
    for(int j=1;j<=m;j++){
        cnt=0;
        for(int i=1;i<=n;i++){
            ret[++cnt]=a[i][j];
        }
        sort(ret+1,ret+1+cnt);
        cnt=unique(ret+1,ret+1+cnt)-ret-1;
        for(int i=1;i<=n;i++){
            pos=lower_bound(ret+1,ret+1+cnt,a[i][j])-ret;
            c[i][j]=pos;
            C[i][j]=cnt-pos;
        }
    }
//    print(c);
//    print(C);
//    print(r);
//    print(R);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",max(c[i][j],r[i][j])+max(R[i][j],C[i][j]));
        }
        puts("");
    }
}

int main(void){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    solve();
    return 0;
}
