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
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
/*head------[@cordercorder]*/

const ll maxn=2e5+10;

ll n,k;
ll h[maxn];
ll num[maxn],sum[maxn],res[maxn];
ll Max,Min;
ll ans;

void solve(){
	sum[0]=0;
	for(ll i=1;i<=Max;i++){
		sum[i]=sum[i-1]+num[i];
		res[i]=sum[i];
	}
	ans=0;
	ll now=0;
	for(ll i=Max;i>Min;i--){
		now+=res[i];
		//deb(now);
		if(now>k){
			ans++;
			now=res[i];
		}
	}
	if(now)
		++ans;
	cout<<ans<<'\n';
}

int main(void){
	FC;
	cin>>n>>k;
	Max=0;
	Min=(ll)(2e5+10);
	for(ll i=1;i<=n;i++){
		cin>>h[i];
		num[1]++;
		num[h[i]+1]--;
		Max=max(Max,h[i]);
		Min=min(Min,h[i]);
	}
	solve();
	return 0;
}
