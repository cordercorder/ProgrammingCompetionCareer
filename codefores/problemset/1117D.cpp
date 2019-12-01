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

const ll maxn=110;
const ll mod=(ll)1e9+7ll;

ll n,m;

struct Matrix{
    ll ma[maxn][maxn];
    void operator=(const Matrix &a){
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=m;j++){
                this->ma[i][j]=a.ma[i][j];
            }
        }
    }
    Matrix(){
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=m;j++){
                ma[i][j]=0;
            }
        }
    }
    Matrix operator*(const Matrix &a){
        Matrix ans;
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=m;j++){
                for(ll k=1;k<=m;k++){
                    ans.ma[i][j]=(ans.ma[i][j]+this->ma[i][k]*a.ma[k][j])%mod;
                }
            }
        }
        return ans;
    }
    void Init(){
        for(ll i=1;i<=m;i++){
            this->ma[i][i]=1;
        }
    }
};

Matrix q_mod(Matrix a,ll b){
    Matrix ans;
    ans.Init();
    while(b){
        if(b&1ll){
            ans=ans*a;
        }
        b>>=1;
        a=a*a;
    }
    return ans;
}

void solve(){
    Matrix ret;
    ret.ma[1][1]=1;
    ret.ma[1][m]=1;
    for(ll i=2;i<=m;i++){
        ret.ma[i][i-1]=1;
    }
    ret=q_mod(ret,n-m+1ll);
    ll ans=0;
    for(ll i=1;i<=m;i++){
        ans=(ans+ret.ma[1][i])%mod;
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld %lld",&n,&m);
    if(n<m){
        puts("1");
    }
    else{
        solve();
    }
    return 0;
}
