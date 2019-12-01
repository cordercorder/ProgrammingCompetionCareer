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
using pii=pair<pair<ll,ll>,ll>;

/*head------[@cordercorder]*/

const ll maxn=(ll)2e5+10ll;

ll n,m;
ll a[maxn];
vector<pii> e;
ll pre[maxn];

ll Find(ll x){
    return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

bool cmp(const pii &a,const pii &b){
    return a.second<b.second;
}

void solve(){
    ll ans=0;
    ll u,v,w;
    ll nu,nv;
    for(ll i=1;i<=n;i++){
        pre[i]=-1;
    }
    ll index=1;
    for(ll i=1;i<=n;i++){
        if(a[i]<a[index]){
            index=i;
        }
    }
    for(ll i=1;i<=n;i++){
        if(i!=index){
            e.push_back(pii(pair<ll,ll>(i,index),a[i]+a[index]));
        }
    }
    sort(e.begin(),e.end(),cmp);
    for(auto it:e){
        u=it.first.first;
        v=it.first.second;
        nu=Find(u);
        nv=Find(v);
        if(nu!=nv){
            ans+=it.second;
            pre[nu]=nv;
        }
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll u,v,w;
    for(ll i=1;i<=m;i++){
        cin>>u>>v>>w;
        e.push_back(pii(pair<ll,ll>(u,v),w));
    }
    solve();
    return 0;
}
