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

const ll maxn=55;
const ll mod=(ll)1e9+7ll;

char s[maxn];
ll dp[maxn][maxn][3];

void solve(){
    ll n=strlen(s+1);
    for(ll i=1;i<=n;i++){
        dp[i][i][(ll)(s[i]-'0')%3ll]=1ll;
    }
    for(ll len=2;len<=n;len++){
        for(ll i=1;i<=n-len+1ll;i++){
            ll j=i+len-1ll;
            ll x=(ll)(s[j]-'0')%3ll;
            if(x==0){
                dp[i][j][0]=(dp[i][j-1][0]*2ll+1ll)%mod;
                dp[i][j][1]=(dp[i][j-1][1]*2ll)%mod;
                dp[i][j][2]=(dp[i][j-1][2]*2ll)%mod;
            }
            else if(x==1){
                dp[i][j][0]=(dp[i][j-1][2]+dp[i][j-1][0])%mod;
                dp[i][j][1]=(dp[i][j-1][0]+dp[i][j-1][1]+1ll)%mod;
                dp[i][j][2]=(dp[i][j-1][1]+dp[i][j-1][2])%mod;
            }
            else{
                dp[i][j][0]=(dp[i][j-1][1]+dp[i][j-1][0])%mod;
                dp[i][j][1]=(dp[i][j-1][2]+dp[i][j-1][1])%mod;
                dp[i][j][2]=(dp[i][j-1][0]+dp[i][j-1][2]+1ll)%mod;
            }
        }
    }
    printf("%lld\n",dp[1][n][0]);
}

int main(void){
    scanf("%s",s+1);
    solve();
    return 0;
}
