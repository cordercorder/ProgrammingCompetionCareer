#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<list>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)2e5+10ll;

ll n;
ll a[maxn];
vector<ll> e[maxn];
ll d[maxn],sum[maxn];
ll ans[maxn];
ll ANS;

void dfs(ll u,ll f,ll depth){
    d[u]=depth;
    sum[u]=a[u];
    ans[u]=a[u]*depth;
    ll v;
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i];
        if(v==f)
            continue;
        dfs(v,u,depth+1ll);
        sum[u]+=sum[v];
        ans[u]+=ans[v];
    }
}

void dfs2(ll u,ll f){
    ll v,tmp;
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i];
        if(v==f)
            continue;
        ans[v]=ans[u]-sum[v]+(sum[1]-sum[v]);
        ANS=max(ANS,ans[v]);
        dfs2(v,u);
    }
}

void solve(){
    dfs(1,0,0);
    ANS=ans[1];
    dfs2(1,0);
    cout<<ANS<<endl;
}

int main(void){
    FC;
    ll u,v;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
