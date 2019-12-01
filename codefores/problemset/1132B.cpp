#include<bits/stdc++.h>
#include<stdint.h>

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

ll a[maxn],n,m,q[maxn];
ll sum[maxn];

void solve(){
    sort(a+1,a+1+n,greater<ll>());
    for(ll i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll ans;
    for(ll i=1;i<=m;i++){
        ans=sum[n]-sum[q[i]]+sum[q[i]-1];
        printf("%lld\n",ans);
    }
}

int main(void){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    scanf("%lld",&m);
    for(ll i=1;i<=m;i++){
        scanf("%lld",&q[i]);
    }
    solve(); 
    return 0;
}
