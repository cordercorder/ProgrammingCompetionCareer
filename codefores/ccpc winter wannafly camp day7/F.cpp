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

const ll maxn=(ll)1e3+10ll;
const ll mod=998244353ll;

ll n,m;
ll b[maxn];
ll num[35],cnt;
ll dp[35][35][2];

ll max_bits(ll x){
    ll ans=0ll;
    while(x){
        x>>=1ll;
        ans++;
    }
    ans--;
    return ans;
}

void pre_handle(ll x){
    cnt=0;
    while(x){
        num[cnt++]=x%2ll;
        x>>=1ll;
    }
}

ll cal(ll pos,ll pos_i,ll bits,bool f){
    if(pos==-1){
        return 1ll;
    }
    if(!f&&dp[pos][pos_i][bits]!=-1){
        return dp[pos][pos_i][bits];
    }
    ll x,ans=0ll;
    if(f){
        x=num[pos];
    }
    else{
        x=1ll;
    }
    for(ll i=0;i<=x;i++){
        if(pos==pos_i){
            if(i==bits){
                ans+=cal(pos-1,pos_i,bits,i==x&&f);
            }
        }
        else{
            ans+=cal(pos-1,pos_i,bits,i==x&&f);
        }
    }
    if(!f){
        dp[pos][pos_i][bits]=ans;
    }
    return ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    pre_handle(m);
    ll tmp,pos,bits,ret,ans=0ll;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            tmp=b[i]^b[j];
            pos=max_bits(tmp);
            bits=((b[j]>>pos)&1ll);
            if(pos>cnt-1ll&&bits==1ll){
                continue;
            }
            if(bits==0){
                ans=(ans+cal(cnt-1ll,pos,bits,true)-1ll+mod)%mod;
            }
            else{
                ans=(ans+cal(cnt-1ll,pos,bits,true))%mod;
            }
        }
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }
    solve();
    return 0;
}
