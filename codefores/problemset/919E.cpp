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
using pii=pair<int,string>; 

/*head------[@cordercorder]*/

ll a,b,p,x,inva,invb;
ll f[1000000+100],cnt;

ll q_mod(ll a,ll b,ll mod){
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

ll cal(ll A,ll B){
    ll tmp=(x-B)/p;
    if(A>tmp)
        return 0ll;
    ll ans=(tmp-A)/cnt+1;
    return ans;
}

void solve(){
    ll inva=q_mod(a,p-2ll,p);
    ll invb=q_mod(b,p-2ll,p);
    ll tmp=1ll;
    cnt=0ll;
    memset(f,-1,sizeof(f));
    while(f[tmp]==-1){
        f[tmp]=cnt++;
        tmp=(tmp*inva)%p;
    }
    ll ret=1ll,ans=0ll;
    for(ll i=0;i<p&&i<=x;i++){
        tmp=ret*i%p*invb%p;
        if(f[tmp]!=-1ll){
            ans+=cal(f[tmp],i);
        }
        ret=(ret*a)%p;
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>a>>b>>p>>x;
    solve();
    return 0;
}
