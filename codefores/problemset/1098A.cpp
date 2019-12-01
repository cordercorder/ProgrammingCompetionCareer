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

const ll maxn=(ll)1e5+10ll;

vector<ll> e[maxn];
ll n; 
ll s[maxn],a[maxn];
bool f;

void dfs(ll u,ll fa,ll lst){
    if(lst!=0&&s[fa]==-1){
        f&=(s[u]-s[lst]>=0);
        a[fa]=min(a[fa],s[u]-s[lst]);
    }
    ll v;
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dfs(v,u,fa);
        }
    }
    if((ll)e[u].size()==0&&s[u]==-1){
        a[u]=0;
    } 
}

void dfs2(ll u,ll fa,ll sum){
    ll v;
    if(a[u]==maxw){
        a[u]=s[u]-sum;
    }
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dfs2(v,u,sum+a[u]);
        }
    }
}

void solve(){
    for(ll i=1;i<=n;i++){
        a[i]=maxw;
    }
    f=true;
    dfs(1,0,0);
    if(!f){
        puts("-1");
        return ;
    }
    dfs2(1,0,0);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans+=a[i];
    }
    printf("%lld\n",ans);
}

int main(void){
    ll p;
    scanf("%lld",&n);
    for(ll i=2;i<=n;i++){
        scanf("%lld",&p);
        e[p].push_back(i);
    }
    for(ll i=1;i<=n;i++){
        scanf("%lld",&s[i]);
    }
    solve();
    return 0;
}
