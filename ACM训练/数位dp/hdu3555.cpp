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
ll dp[30][3];
ll a[30],cnt;

void bit(ll x){
	cnt=0;
	while(x){
		a[++cnt]=x%10;
		x/=10;
	}
}

void pre_handle(){
	dp[0][0]=1;
	for(ll i=1;i<=20;i++){
		dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
	}
}

void solve(){
	bit(n+1);
	ll ans=0;
	bool f=false;
	for(ll i=cnt;i>=1;i--){
		ans+=(dp[i-1][2]*a[i]);
		if(f){
			ans+=(a[i]*dp[i-1][0]);
		}
		if(!f&&a[i]>4){
			ans+=dp[i-1][1];
		}
		if(i!=cnt&&a[i+1]==4&&a[i]==9){
			f=true;
		}
	}
	cout<<ans<<'\n';
}

int main(void){
	FC;
	pre_handle();
	cin>>t;
	while(t--){
		cin>>n;
		solve();
	}
	return 0;
}
