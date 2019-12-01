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

ll T;
ll n,x,y;
ll b[maxn]; 
ll nx,ny;
vector<ll> id[maxn];

void solve(){
    nx=0,ny=0;
    for(ll i=1;i<=n;i++){
        nx+=b[i]*i;
        ny+=b[i]*b[i]*i;
    }
    ll resx=nx-x,resy=ny-y,ans=0,tmp;
    if(resx==0){
        if(resy!=0){
            puts("0");
            return ;
        }
        for(ll i=1;i<=n;i++){
            if(!id[b[i]].empty()){
                tmp=(ll)id[b[i]].size();
                ans+=(tmp*(tmp-1ll))/2ll;
                id[b[i]].clear();
            }
        }
        printf("%lld\n",ans);
    }
    else{
        if(resy%resx!=0){
            puts("0");
            return ;
        }
        ll ret=resy/resx,pos;
        for(ll i=1;i<=n;i++){
            ll v=ret-b[i];
            if(v>=1&&(ll)id[v].size()>0&&v!=b[i]){
                if(resx%(v-b[i])==0ll){
                    ll tmp=resx/(v-b[i])+i;
                    pos=lower_bound(id[v].begin(),id[v].end(),tmp)-id[v].begin();
                    if(pos!=(ll)id[v].size()&&id[v][pos]==tmp){
                        ans++;
                    }
                }
            }
        }
        ans/=2ll;
        printf("%lld\n",ans);
    }
}

int main(void){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld %lld %lld",&n,&x,&y);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&b[i]);
            id[b[i]].push_back(i); 
        }
        solve();
        for(ll i=1;i<=n;i++){
            if(!id[b[i]].empty())
                id[b[i]].clear();
        }
    }
    return 0;
}
