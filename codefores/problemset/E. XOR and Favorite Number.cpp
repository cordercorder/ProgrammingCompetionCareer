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

const int max_n=1e7+10;
const int maxn=1e5+10;

struct node{
	ll l;
	ll r;
	ll id;
}Q[maxn];

ll pos[maxn];
ll flag[max_n],a[maxn];
ll n,m,k;
ll sum[maxn];
ll len;
ll ans[maxn],res;

bool cmp(const node &a,const node &b){
	if(pos[a.l]==pos[a.r])
		return a.r<b.r;
	return pos[a.l]<pos[b.l];
}

void add(ll x){
	res+=flag[sum[x]^k];
	flag[sum[x]]++;
}

void del(ll x){
	flag[sum[x]]--;
	res-=flag[sum[x]^k];
}

void solve(){
	ll L=1,R=0;
	sort(Q+1,Q+1+m,cmp);
	flag[0]=1;
	for(ll i=1;i<=m;i++){
		while(L<Q[i].l){
			del(L-1);
			L++;
		}
		while(L>Q[i].l){
			L--;
			add(L-1);
		}
		while(R<Q[i].r){
			R++;
			add(R);
		}
		while(R>Q[i].r){
			del(R);
			R--;
		}
		ans[Q[i].id]=res;
	}
	for(ll i=1;i<=m;i++){
		printf("%lld\n",ans[i]);
	}
}

int main(void){
	scanf("%lld %lld %lld",&n,&m,&k);
	sum[0]=0;
	len=sqrt(n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
		pos[i]=i/len;
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&Q[i].l,&Q[i].r);
		Q[i].id=i;
	}
	solve();
	return 0;
}
