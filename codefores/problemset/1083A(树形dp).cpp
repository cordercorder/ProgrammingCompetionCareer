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
void err(int a){
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

const ll maxn=(ll)3e5+10ll;

vector<pii> e[maxn];
ll n;
ll w[maxn];
ll dp[maxn][2];
ll ans;

void dfs(ll u,ll f){
    ll v;
    ll maxe1=0ll,maxe2=0ll;
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i].first;
        if(v!=f){
            dfs(v,u);
            if((dp[v][0]-e[u][i].second)>=maxe1){
                maxe2=maxe1;
                maxe1=dp[v][0]-e[u][i].second;
            }
            else if((dp[v][0]-e[u][i].second)>maxe2){
                maxe2=dp[v][0]-e[u][i].second;
            }
        }
    }
    dp[u][0]+=(maxe1+w[u]);
    dp[u][1]+=(maxe2+w[u]);
    ans=max(ans,maxe1+maxe2+w[u]);
}

int main(void){
    FC;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>w[i];
    }
    ll u,v,c;
    for(ll i=1;i<n;i++){
        cin>>u>>v>>c;
        e[u].push_back(pii(v,c));
        e[v].push_back(pii(u,c));
    }
    dfs(1,0);
    cout<<ans<<'\n';
    return 0;
}
