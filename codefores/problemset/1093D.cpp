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

const ll maxn=(ll)3e5+10ll;
const ll mod=998244353ll;

ll num[maxn];
ll t,n,m;
vector<ll> e[maxn];
ll color[maxn];
ll res1,res2;

bool dfs(ll u,ll c){
    color[u]=c;
    if(c==1){
        res1++;
    }
    else{
        res2++;
    }
    ll v;
    for(ll i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(color[v]==0&&dfs(v,-c)==false){
            return false;
        }
        else if(color[v]==color[u])
            return false;
    }
    return true;
}

void solve(){
    ll ans=1ll;
    for(ll i=1;i<=n;i++){
        color[i]=0;
    }
    for(ll i=1;i<=n;i++){
        if(color[i]==0){
            res1=0;
            res2=0;
            if(dfs(i,1ll)){
                ans=ans*((num[res1]+num[res2])%mod)%mod;
            }
            else{
                puts("0");
                return ;
            }
        }
    }
    printf("%lld\n",ans);
}

int main(void){
    ll u,v;
    num[0]=1ll;
    for(ll i=1;i<=300000ll;i++){
        num[i]=num[i-1]*2ll%mod;
    }
    for(scanf("%lld",&t);t--;){
        scanf("%lld %lld",&n,&m);
        for(ll i=0;i<m;i++){
            scanf("%lld %lld",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        solve();
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
    }
    return 0;
}
