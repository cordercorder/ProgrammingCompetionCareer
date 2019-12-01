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

const int maxn=5010;

int n;
int c[maxn];
int dp[maxn][maxn][2];

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]=(int)1e9;
            }
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][i][0]=0;
        dp[i][i][1]=0;
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=len+l-1;
            dp[l][r][0]=min(dp[l][r][0],dp[l+1][r][0]+(int)(c[l+1]!=c[l]));
            dp[l][r][0]=min(dp[l][r][0],dp[l+1][r][1]+(int)(c[r]!=c[l]));
            dp[l][r][1]=min(dp[l][r][1],dp[l][r-1][0]+(int)(c[l]!=c[r]));
            dp[l][r][1]=min(dp[l][r][1],dp[l][r-1][1]+(int)(c[r-1]!=c[r]));
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1])<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    solve();
    return 0;
}
