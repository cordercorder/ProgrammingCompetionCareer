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
using pii=pair<ll,ll>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)1e6+10ll;
const ll mod=(ll)1e9+7ll;

vector<pii> res;
vector<ll> e[maxn];

ll n,m,N;
ll ans,sum[maxn];

void handle(){
    ll plus=0;
    ll u,v;
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<(ll)res.size();j++){
            u=res[j].first+plus;
            v=res[j].second+plus;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        plus+=n;
    }
}

void dfs(ll u,ll f){
    ll v;
    sum[u]=1ll;
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i];
        if(v==f)
            continue;
        dfs(v,u);
        sum[u]+=sum[v];
    }
    ans=(ans+(N-sum[u])*(sum[u])%mod)%mod;
}

void solve(){
    N=n*m;
    ans=0ll;
    dfs(1,0);
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    ll u,v,a,b;
    for(ll i=1;i<n;i++){
        cin>>u>>v;
        res.push_back(pii(u,v));
    }
    handle();
    for(ll i=1;i<m;i++){
        cin>>a>>b>>u>>v;
        u+=(a-1ll)*n;
        v+=(b-1ll)*n;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
