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

const int maxn=(int)2e3+10;

int n,m;
char s[maxn];
int add[30],del[30];
int dp[maxn][maxn];

void solve(){
    for(int len=2;len<=m;len++){
        for(int l=1;l<=m-len+1;l++){
            int r=l+len-1;
            int mine=(int)1e9+10;
            if(s[l]==s[r])
                mine=min(mine,dp[l+1][r-1]);
            else{
                mine=min(mine,dp[l+1][r]+add[(int)(s[l]-'a')]);
                mine=min(mine,dp[l+1][r]+del[(int)(s[l]-'a')]);
                mine=min(mine,dp[l][r-1]+add[(int)(s[r]-'a')]);
                mine=min(mine,dp[l][r-1]+del[(int)(s[r]-'a')]);
            } 
            dp[l][r]=mine;
        }
    }
    cout<<dp[1][m]<<'\n';
}

int main(void){
    FC;
    char tmp[5];
    int a,b;
    cin>>n>>m;
    cin>>(s+1);
    for(int i=1;i<=n;i++){
        cin>>tmp>>a>>b;
        add[(int)(tmp[0]-'a')]=a;
        del[(int)(tmp[0]-'a')]=b;
    }
    solve();
    return 0;
}
