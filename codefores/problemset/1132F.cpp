#include<bits/stdc++.h>
#include<stdint.h>

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

const int maxn=510;

int n;
char s[maxn];
int dp[maxn][maxn];

void solve(){
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=l+len-1;
            dp[l][r]=dp[l+1][r]+1;
            for(int i=l+1;i<=r;i++){
                if(s[l]==s[i]){
                    dp[l][r]=min(dp[l][r],dp[l+1][i-1]+dp[i][r]);
                }
            }
        }
    }
    printf("%d\n",dp[1][n]);
}

int main(void){
    scanf("%d",&n);
    scanf("%s",s+1);
    solve();
    return 0;
}
