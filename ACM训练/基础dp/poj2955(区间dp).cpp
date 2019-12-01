#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<list>
#include<set>
#include<map>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

void err(int a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

/*head------[@cordercorder]*/

const int maxn=110;

int dp[maxn][maxn]; 
char s[maxn];

void solve(){
    int N=strlen(s+1);
    memset(dp,0,sizeof(dp));
    for(int len=2;len<=N;len++){
        for(int l=1;l<=N-len+1;l++){
            int r=l+len-1;
            if((s[l]=='['&&s[r]==']')||(s[l]=='('&&s[r]==')')){
                dp[l][r]=max(dp[l][r],dp[l+1][r-1]+2);
            }
            for(int i=l;i<r;i++){
                dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]);
            }
        }
    }
    cout<<dp[1][N]<<'\n';
}

int main(void){
    FC;
    while(cin>>(s+1)){
        if(s[1]=='e')
            break;
        solve();
    }
    return 0;
}
