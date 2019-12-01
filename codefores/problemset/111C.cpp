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
using pii=pair<ll,ll>;

/*head------[@cordercorder]*/

const int maxn=(int)1e5+10;

ll n,k,A,B;
ll a[maxn];
map<ll,ll> mp;
vector<ll> index;
unordered_map<ll,ll> sum;

ll create(ll rt,ll l,ll r){
    if((upper_bound(index.begin(),index.end(),r)-lower_bound(index.begin(),index.end(),l))==0){
        return A;
    }
    if(l==r){
        sum[rt]+=mp[l]; 
        return mp[l]*B;
    }
    ll mid=(l+r)>>1;
    ll ans=create(rt<<1,l,mid)+create(rt<<1|1,mid+1,r);
    sum[rt]=(sum[rt<<1]+sum[rt<<1|1]);
    ans=min(ans,sum[rt]*B*(r-l+1));
    return ans;
}

void solve(){
    for(auto it:mp){
        index.push_back(it.first);
    }
    ll len=(1ll<<n);
    ll ans=create(1,1,len);
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>k>>A>>B;
    for(ll i=1;i<=k;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    solve();
    return 0;
}
