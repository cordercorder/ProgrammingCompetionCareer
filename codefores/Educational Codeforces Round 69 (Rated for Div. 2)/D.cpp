#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)
#define local

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

const ll maxn=(ll)3e5+10ll;

ll n,m,k;
ll a[maxn],dp[maxn][15];

void solve(){
    ll ans=0;
    for(ll i=0;i<=m;i++){
        dp[0][i]=-(ll)1e17;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(j==1){
                dp[i][j]=max(a[i],dp[i-1][m]+a[i])-k;
            }
            else{
                dp[i][j]=dp[i-1][j-1]+a[i];
            }
            ans=max(ans,dp[i][j]);
        }
    }

    printf("%lld\n",ans);
}

int main(void){

#ifdef local
    freopen("D.in","r",stdin);
#endif

    scanf("%lld %lld %lld",&n,&m,&k);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    return 0;
}
