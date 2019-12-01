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
const long long maxw=(long long)1e18+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

/*head------[@cordercorder]*/

const ll maxn=(ll)1e6+10ll;

ll n,b;
bool isv[maxn];
vector<ll> pre,fac;
ll num[maxn],res[maxn];

void pre_handle(){
    for(ll i=2;i<=1000000ll;i++){
        if(!isv[i]){
            pre.push_back(i);
            for(ll j=i*i;j<=1000000ll;j+=i){
                isv[j]=true;
            }
        }
    }
}

void handle(ll x){
    for(ll i=0;i<(ll)pre.size()&&pre[i]*pre[i]<=x;i++){
        if(x%pre[i]==0){
            fac.push_back(pre[i]);
            ll pos=(ll)fac.size()-1ll;
            while(x%pre[i]==0){
                res[pos]++;
                x/=pre[i];
            }
        }
        if(x==1)
            break;
    }
    if(x!=1){
        fac.push_back(x);
        ll pos=(ll)fac.size()-1ll;
        res[pos]++;
    }
}

void solve(){
    ll ans=maxw;
    handle(b);
    for(ll i=0;i<(ll)fac.size();i++){
        ll tmp=n;
        while(tmp){
            num[i]+=tmp/fac[i];
            tmp/=fac[i];
        } 
    }
    for(ll i=0;i<(ll)fac.size();i++){
        ans=min(ans,num[i]/res[i]);
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    pre_handle();
    cin>>n>>b;
    solve();
    return 0;
}
