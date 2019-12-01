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

const int maxn=(int)2e5+10;
const ll mod=(ll)1e9+7ll;

int n,k;
vector<pii> e[maxn];
bool isv[maxn];
int cnt;

void dfs(int u){
    int v;
    isv[u]=true;
    cnt++;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].first;
        if(!isv[v]&&e[u][i].second==0){
            dfs(v);
        }
    }
}

ll q_mod(ll a,ll b){
    ll ans=1ll;
    while(b){
        if(b&1ll){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1ll;
    }
    return ans;
}

void solve(){
    ll ans=q_mod((ll)n,(ll)k);
    for(int i=1;i<=n;i++){
        if(!isv[i]){
            cnt=0;
            dfs(i);
            ans=(ans-q_mod((ll)cnt,(ll)k)+mod)%mod;
        }
    }
    printf("%lld\n",ans);
}

int main(void){
    int u,v,x;
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&x);
        e[u].push_back(pii(v,x));
        e[v].push_back(pii(u,x));
    }
    solve();
    return 0;
}
