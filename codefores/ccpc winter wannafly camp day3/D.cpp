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

const ll maxn=20;

struct node{
    ll to;
    ll w;
}; 
bool isv[maxn];
ll D[maxn];
vector<node> e[maxn];
ll n,m;
ll sum[maxn];
ll in[maxn];
vector<node> res;

void dfs(ll u){
    isv[u]=true;
    sum[u]=1ll;
    ll v,w;
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i].to;
        w=e[u][i].w;
        if(!isv[v]){
            dfs(v);
            sum[u]+=sum[v];
            ll tmp=sum[v]*(n-sum[v])*w;
            res.push_back({v,tmp});
        }
    }
}

void solve(){
    dfs(1);
    for(ll i=0;i<(ll)res.size();i++){
        deb(res[i].w);
    }
    
}

int main(void){
    FC;
    cin>>n>>m;
    ll u,v,w;
    for(ll i=0;i<m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        in[v]++;
    }
    solve();
    
    return 0;
}
