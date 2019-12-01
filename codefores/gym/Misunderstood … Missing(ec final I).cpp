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
using pii=pair<int,string>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)1e2+10ll;

struct node{
    ll a;
    ll b;
    ll c;
};

ll T;
ll n;
node res[maxn];
ll dp[2][maxn][maxn*maxn/2];

void solve(){
    dp[n%2ll][1][n]=res[n].a;
    for(ll i=n-1;i>=1ll;i--){
        for(ll j=1ll;j<=n-i;j++){
            ll l=(i+i+j-1ll)*j/2ll,r=(n+n-j+1ll)*j/2ll+1ll;
            for(ll k=l;k<r;k++){
                dp[i%2ll][j+1ll][k+i]=max(dp[i%2ll][j+1ll][k+i],dp[(i+1)%2ll][j][k]+res[i].a);
                dp[i%2ll][j][k]=max(dp[i%2ll][j][k],dp[(i+1)%2ll][j][k]+(k-j*i)*res[i].b);
                dp[i%2ll][j][k]=max(dp[i%2ll][j][k],dp[(i+1)%2ll][j][k]+j*res[i].c);
            }
        }
    }
    ll ans=0ll;
    for(ll j=1;j<=n;j++){
        for(ll k=1;k<=5050ll;k++){
            ans=max(ans,dp[1][j][k]);
        }
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>T;
    while(T--){
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>res[i].a>>res[i].b>>res[i].c;
        }
        solve();
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
