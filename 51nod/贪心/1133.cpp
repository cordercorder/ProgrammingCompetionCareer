#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e4+10;

struct node{
	ll l;
	ll r;
}res[maxn];

ll n;
ll dp[maxn];

bool cmp(const node &a,const node &b){
	if(a.l<b.l)
		return 1;
	if(a.l==b.l&&a.r<b.r)
		return 1;
	return 0;
}

void solve(){
	ll ans=0;
	sort(res+1,res+1+n,cmp);
	for(ll i=1;i<=n;i++){
		dp[i]=1;
		for(ll j=1;j<=n;j++){
			if(res[j].r<=res[i].l){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
}

int main(void){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//clock_t st=clock();
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld",&res[i].l,&res[i].r);
	}
	solve();
	//clock_t ed=clock();
	//cout<<"running time is "<<(double)(ed-st)<<"ms"<<endl;
	return 0;
}
