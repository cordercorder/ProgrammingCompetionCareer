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

int n;
ll dp[510][510];

void solve(){
    for(ll len=3;len<=n;len++){
        for(ll l=1;l<=n-len+1;l++){
            ll r=l+len-1;
            dp[l][r]=(ll)1e17;
            for(ll i=l+1;i<r;i++){
                dp[l][r]=min(dp[l][r],dp[l][i]+dp[i][r]+l*i*r);
            }
        }
    }
    printf("%lld\n",dp[1][n]);
}

int main(void){
    scanf("%d",&n);
    solve();
    return 0;
}
