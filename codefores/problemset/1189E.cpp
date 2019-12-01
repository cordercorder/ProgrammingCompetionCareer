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

const ll maxn=(ll)3e5+10ll;

ll n,p,k; 
ll a[maxn];
map<ll,ll> cnt;

ll mul(ll a,ll b){
    ll ans=a*b%p;
    return ans;
}

void solve(){
    ll tmp,ans=0ll;
    for(ll i=1;i<=n;i++){
        tmp=mul(a[i],a[i])*mul(a[i],a[i])%p-mul(k,a[i])%p;
        tmp=(tmp+p)%p;
        cnt[tmp]++;
    }
    for(pair<ll,ll> e:cnt){
        ans+=(e.second*(e.second-1ll))/2ll;
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld %lld %lld",&n,&p,&k);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    return 0;
}
