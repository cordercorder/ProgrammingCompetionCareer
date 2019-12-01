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

const int maxn=1e5+10;

struct node{
	ll p;
	ll c;
	ll sum;
	ll id;
}res[maxn];

multiset<ll> Q;
ll n,k;
ll ans[maxn];

bool cmp(const node &a,const node &b){
	return a.p<b.p;
}

void solve(){
	sort(res+1,res+1+n,cmp);
	ll ret=0;
	Q.insert(res[1].c);
	ret+=res[1].c;
	for(ll i=2;i<=n;i++){
		res[i].sum+=ret;
		//deb(ret);
		if(Q.size()<k){
			Q.insert(res[i].c);
			ret+=(res[i].c);
		}
		else{
			if((*Q.begin())<res[i].c){
				ret-=(*Q.begin());
				Q.erase(Q.begin());
				Q.insert(res[i].c);
				ret+=(res[i].c);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		ans[res[i].id]=res[i].sum;
	}
	for(ll i=1;i<=n;i++){
		printf("%lld ",ans[i]);
	}
	puts("");
}

int main(void){
	scanf("%lld %lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&res[i].p);
		res[i].id=i;
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&res[i].c);
		res[i].sum=res[i].c; 
	}
	if(k==0){
		for(ll i=1;i<=n;i++){
			printf("%lld ",res[i].c);
		}
		return 0;
	}
	solve();
	return 0;
}
