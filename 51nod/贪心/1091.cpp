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

const ll maxn=5e4+10;

struct node{
	ll l;
	ll r;
}res[maxn];
ll n;

bool cmp(const node &a,const node &b){
	if(a.l<b.l)
		return 1;
	if(a.l==b.l&&a.r>b.r)
		return 1;
	return 0;
}

void solve(){
	sort(res+1,res+1+n,cmp);
	ll ans=0,R=res[1].r;
	for(ll i=2;i<=n;i++){
		if(R>=res[i].r){
			ans=max(ans,res[i].r-res[i].l);
		}
		else{
			ans=max(ans,R-res[i].l);
			R=res[i].r;
		}
	}
	printf("%lld\n",ans);
}

int main(void){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld",&res[i].l,&res[i].r);
	}
	solve();
	return 0;
}
