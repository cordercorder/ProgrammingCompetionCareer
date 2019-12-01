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
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=2e3+10;

ll s[2][maxn];
ll T;
ll k1,k2,c;
ll n,m;
bool isv[maxn][maxn];
ll dp[maxn][maxn];

ll solve(ll pos1,ll pos2,ll res){
    if(pos1<=n&&pos2<=m&&isv[pos1][pos2]){
        return dp[pos1][pos2];
    }
    if(pos1<=n&&pos2<=m&&res>=s[0][pos1]&&res>=s[1][pos2]){
        ll tmp1=solve(pos1+1,pos2,res-s[0][pos1])+k1*(res-s[0][pos1]);
        ll tmp2=solve(pos1,pos2+1,res-s[1][pos2])+k2*(res-s[1][pos2]);
        isv[pos1][pos2]=true;
        return dp[pos1][pos2]=max(tmp1,tmp2);
    }
    else if(pos1<=n&&res>=s[0][pos1]){
        ll tmp=solve(pos1+1,pos2,res-s[0][pos1])+k1*(res-s[0][pos1]);
        isv[pos1][pos2]=true;
        return dp[pos1][pos2]=tmp;
    }
    else if(pos2<=m&&res>=s[1][pos2]){
        ll tmp=solve(pos1,pos2+1,res-s[1][pos2])+k2*(res-s[1][pos2]);
        isv[pos1][pos2]=true;
        return dp[pos1][pos2]=tmp;
    }
    else
        return 0;
}

int main(void){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld %lld %lld",&k1,&k2,&c);
        scanf("%lld %lld",&n,&m);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&s[0][i]);
        }
        for(ll i=1;i<=m;i++){
            scanf("%lld",&s[1][i]);
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                isv[i][j]=false;
            }
        }
        sort(s[0]+1,s[0]+n+1);
        sort(s[1]+1,s[1]+m+1);
        printf("%lld\n",solve(1ll,1ll,c));
    }
	return 0;
}
