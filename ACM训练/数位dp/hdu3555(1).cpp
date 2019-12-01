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

ll t,n;
ll num[25],cnt;
ll dp[25][3][2];

void bits(ll x){
	cnt=0;
	while(x){
		num[++cnt]=x%10;
		x/=10;
	}
}

ll dfs(ll pos,ll la,bool f){// la==0,末尾不为4;la==1末尾为4;la==2表示末尾为49
	if(pos<=0){
		if(la==2)
			return 1;
		return 0;
	}
	if(dp[pos][la][f]!=-1){
		return dp[pos][la][f];
	}
	ll x;
	if(f){
		x=num[pos];
	}
	else{
		x=9;
	}
	ll n_la,res=0;
	for(ll i=0;i<=x;i++){
		n_la=la;
		if(la==0&&i==4){
			n_la=1;
		}
		if(la==1&&i!=4){
			n_la=0;
		}
		if(la==1&&i==9){
			n_la=2;
		}
		res+=dfs(pos-1,n_la,f&&i==x);
	}
	return dp[pos][la][f]=res;
}

void solve(){
	memset(dp,-1,sizeof(dp));
	bits(n);
	printf("%lld\n",dfs(cnt,0,1));
}

int main(void){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		solve();
	}
	return 0;
}
