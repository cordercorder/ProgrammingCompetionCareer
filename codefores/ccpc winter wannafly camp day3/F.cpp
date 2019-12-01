#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    for(auto i:a){
        cerr<<i<<" ";
    }
    cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}
void err(long long a){
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

const ll maxn=(ll)1e7+10ll;
const ll mod=998244353ll;

bool check[maxn];
ll prime[maxn],mu[maxn];
ll sum[maxn];
ll n;

void Moblus(){
    mu[1]=1ll;
    ll tot=0;
    for(ll i=2;i<maxn;i++){
        if(!check[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(ll j=0;j<tot;j++){
            if(i*prime[j]>maxn)
                break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0ll){
                mu[i*prime[j]]=0ll;
                break;
            }
            else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
    for(ll i=1;i<maxn;i++){
        sum[i]=sum[i-1]+mu[i];
//        deb(sum[i]);
    }
}

ll cal(ll N){
    ll ans=0;
    for(ll l=1,r;l<=N;l=r+1){
        r=N/(N/l);
        ll tmp=(sum[r]-sum[l-1])*(N/l)%mod*(N/l)%mod;
        ans=(ans+tmp)%mod;
    }
    ans=(ans+mod)%mod;
    return ans;
}

void solve(){
    ll ans=0;
    for(ll l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        ll d=(sum[r]-sum[l-1]);
        ll tmp=cal(n/l);
        ans=(ans+tmp*d%mod)%mod;
    }
    ans=(ans+mod)%mod;
    cout<<ans<<'\n';
}

int main(void){
    Moblus();
    FC;
    cin>>n;
    solve();
    return 0;
}
