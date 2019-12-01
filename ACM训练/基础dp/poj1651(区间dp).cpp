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

int a[maxn];
int n;
int dp[maxn][maxn];

void solve(){
    for(int len=3;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=l+len-1;
            int mine=(int)1e9+10;
            for(int k=l+1;k<r;k++){
                mine=min(mine,dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]);
            }
            dp[l][r]=mine;
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }    
    cout<<dp[1][n]<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    solve();
    return 0;
}
