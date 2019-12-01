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

const int maxn=(int)1e5+10;

ll T;
ll n,a[maxn],b[maxn],c[maxn],d[maxn];
ll res[maxn+maxn]; 

ll cal(ll *x,ll *y){
    ll cnt=0,ans=0;
    for(int i=1;i<=n;i++){
        res[++cnt]=x[i];
        res[++cnt]=y[i];
    }
    sort(res+1,res+1+cnt);
    ll tot=res[(cnt+1)/2];
    for(int i=1;i<=n;i++){
        ans+=(abs(x[i]-tot)+abs(y[i]-tot)-(y[i]-x[i]))/2ll;
    }
    return ans;
}

void solve(){
    ll ans=0;
    ans+=cal(a,c);
    ans+=cal(b,d);
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld %lld %lld %lld",&a[i],&b[i],&c[i],&d[i]);
        }
        solve();
    }
    return 0;
}
