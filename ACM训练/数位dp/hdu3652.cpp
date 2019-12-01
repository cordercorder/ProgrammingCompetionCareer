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
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

ll n;
ll num[20],cnt;
ll dp[15][15][3][2];

void bits(ll x){
	cnt=0;
	while(x){
		num[++cnt]=x%10;
		x/=10;
	}
}

ll dfs(ll pos,ll mod,ll la,bool f){//la=0末尾不为1，la=1末尾为1，la=2末尾为13
	ll x;
	if(pos<=0){
		if(mod==0&&la==2)
			return 1;
		return 0;
	}
	if(dp[pos][mod][la][f]!=-1)
		return dp[pos][mod][la][f];
	if(f){
		x=num[pos];
	}
	else{
		x=9;
	}
	ll n_mod,n_la,res=0;
	for(ll i=0;i<=x;i++){
		n_mod=(mod*10+i)%13LL;
		n_la=la;
		if(la==0&&i==1){
			n_la=1;
		}
		if(la==1&&i!=1){
			n_la=0;
		}
		if(la==1&&i==3){
			n_la=2;
		}		
		res+=dfs(pos-1,n_mod,n_la,f&&i==x);
	}
	return dp[pos][mod][la][f]=res;
}

void solve(){
	memset(dp,-1,sizeof(dp));
	bits(n);
	printf("%lld\n",dfs(cnt,0,0,1));
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		solve();
	}
	return 0;
}
