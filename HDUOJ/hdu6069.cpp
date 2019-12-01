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
void err(int a){
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

const ll mod=998244353ll;
const ll maxn=(ll)1e6+10ll;

ll T;
ll l,r,k;
ll cnt;
bool isv[maxn];
ll prime[maxn];

void Prime(ll x){
    cnt=0ll;
    for(ll i=2;i<x;i++){
        if(!isv[i])
            prime[cnt++]=i;
        for(ll j=0;j<cnt&&i*prime[j]<x;j++){
            isv[i*prime[j]]=true;
            if(i%prime[j]==0ll)
                break;
        }
    }
}

ll handle(ll x){
    ll ans=1ll,sum;
    bool f;
    for(ll i=0;i<cnt&&prime[i]*prime[i]<=x;i++){
        sum=0ll;
        f=false;
        while(x%prime[i]==0ll){
            x/=prime[i];
            sum++;
            f=true;
        }
        if(f){
            sum*=k;
            ans=(ans*(sum+1ll));
        }
        if(x==1ll)
            break;
    }
    if(x!=1ll){
        ans=(ans*(k+1ll));
    }
    return ans;
}

void solve(){
    ll ans=0ll;
    for(ll i=l;i<=r;i++){
        ans=(ans+handle(i))%mod;
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    Prime(maxn);
    cin>>T;
    while(T--){
        cin>>l>>r>>k;
        solve();
    }
    return 0;
}
