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

const ll mod=998244353ll;
const ll maxn=(ll)2e3+10ll;

ll n,m;
ll a[maxn][maxn];
char s[maxn][maxn];

void solve(){
    ll ans=0ll;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            a[i][j]=(ll)(s[i][j]-'0');
            if(a[i][j]==1ll){
                ans=(ans+i*j*(n-i+1ll)*(m-j+1ll))%mod;
            }
        }
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>(s[i]+1);
    }
    solve();
    return 0;
}
