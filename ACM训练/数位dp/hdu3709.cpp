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

ll t,x,y;

ll tmp[25],cnt;
ll dp[22][22][1400][2];

void bits(ll x){
	cnt=0;
	while(x){
		tmp[++cnt]=x%10;
		x/=10;	
	}
}

ll dfs(ll pos,ll piv,ll sum,bool f){
	if(pos==0){
		return sum==0;
	}
	if(dp[pos][piv][sum][f]!=-1)
		return dp[pos][piv][sum][f];
	ll num;
	if(f){
		num=tmp[pos];
	}
	else{
		num=9;
	}
	ll ans=0;
	for(ll i=0;i<=num;i++){
		ans+=dfs(pos-1,piv,sum+i*(pos-piv),f&&i==num);
	}
	return dp[pos][piv][sum][f]=ans;
}

ll solve(ll res){
	bits(res);
	ll ans=0;
	for(ll i=1;i<=cnt;i++){
		memset(dp,-1,sizeof(dp));
		ans+=dfs(cnt,i,0,1);
	}
	ans-=(cnt-1);
	return ans;
}

int main(void){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",solve(y)-solve(x-1));
	}
	return 0;
}
