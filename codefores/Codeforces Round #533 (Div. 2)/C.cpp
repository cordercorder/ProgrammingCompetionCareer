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

const ll mod=(ll)1e9+7ll;
const ll maxn=(ll)2e5+10ll;


ll n,l,r;
ll dp[maxn][4];

void solve(){
    ll res0=(r/3ll)-(l-1ll)/3ll;
    ll res1=((r+2ll)/3ll)-(l+2ll-1ll)/3ll;
    ll res2=((r+1ll)/3ll)-(l+1ll-1ll)/3ll;
//    deb(res0);
//    deb(res1);
//    deb(res2);
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        dp[i][0]=(dp[i-1][0]*res0%mod+dp[i-1][1]*res2%mod+dp[i-1][2]*res1%mod)%mod;
        dp[i][1]=(dp[i-1][0]*res1%mod+dp[i-1][1]*res0%mod+dp[i-1][2]*res2%mod)%mod;
        dp[i][2]=(dp[i-1][0]*res2%mod+dp[i-1][1]*res1%mod+dp[i-1][2]*res0%mod)%mod;
//        for(ll j=0;j<3;j++){
//            cout<<dp[i][j]<<" "; 
//        }
//        cout<<'\n';
    }
    cout<<dp[n][0]<<'\n';
}

int main(void){
    FC;
    cin>>n>>l>>r;
    solve();
    return 0;
}
