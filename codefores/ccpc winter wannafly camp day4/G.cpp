#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    for(auto i:a){
        cerr<<i<<" ";
    }
    cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}
void err(long long a){
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

const ll MOD=(ll)1e9+7ll;
const ll N=(ll)1e3+10ll;

ll n;
ll F[N], Finv[N], inv[N];//F是阶乘，Finv是逆元的阶乘
ll a[N];

void init(){
    inv[1] = 1;
    for(ll i = 2; i < N; i ++){
        inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
    }
    F[0] = Finv[0] = 1;
    for(ll i = 1; i < N; i ++){
        F[i] = F[i-1] * 1ll * i % MOD;
        Finv[i] = Finv[i-1] * 1ll * inv[i] % MOD;
    }
}

ll comb(ll n, ll m){//comb(n, m)就是C(n, m) 
    if(m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
}

ll q_mod(ll a,ll b){
    ll ans=1ll;
    while(b){
        if(b&1ll){
            ans=ans*a%MOD;
        }
        b>>=1ll;
        a=a*a%MOD;
    }
    return ans;
}

void solve(){
    init();
    a[0]=1ll;
    a[1]=1ll;
    ll sum;
    ll inv_two=q_mod(2ll,MOD-2ll);
    for(ll i=1;i<=n;i++){
        sum=0;
        for(ll k=0;k<=i;k++){
            sum=(sum+comb(i,k)*a[k]%MOD*a[i-k]%MOD)%MOD;
        }
        a[i+1]=sum*inv_two%MOD;
    }
    cout<<a[n]<<'\n';
}

int main(void){
    FC;
    cin>>n;
    solve();
    return 0;
}
