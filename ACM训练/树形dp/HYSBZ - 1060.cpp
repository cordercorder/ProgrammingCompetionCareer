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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

/*head------[@cordercorder]*/

const ll maxn=(ll)5e5+10ll;

vector<pii> e[maxn];
ll n,root;
ll dp[maxn];
ll ans;

void dfs(ll u,ll f){
    ll v;
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i].first;
        if(v!=f){
            dfs(v,u);
            dp[u]=max(dp[u],dp[v]+e[u][i].second);
        }
    }
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i].first;
        if(v!=f){
            ans+=(dp[u]-dp[v]-e[u][i].second);
        }
    }
}

void solve(){
    ans=0;
    dfs(root,0);
    cout<<ans<<'\n';
}

int main(void){
    FC;
    ll u,v,w;
    cin>>n>>root;
    for(ll i=1;i<n;i++){
        cin>>u>>v>>w;
        e[u].push_back(pii(v,w));
        e[v].push_back(pii(u,w));
    }
    solve();
    return 0;
}
