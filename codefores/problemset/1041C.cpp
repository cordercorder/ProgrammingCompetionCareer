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

const ll maxn=2e5+10;

ll n,m,d;
ll ans[maxn];
ll b[maxn];
priority_queue<ll,vector<ll>,greater<ll> > q;

struct node{
	ll num;
	ll id;
}a[maxn];

bool cmp(const node &a,const node &b){
	return a.num<b.num;
}

void solve(){
	sort(a+1,a+1+n,cmp);
	ll tt=0;
	for(ll i=1;i<=n;i++){
		if(q.empty()){
			ans[a[i].id]=++tt;
			q.push(i);
			continue;
		}
		if(a[i].num-a[q.top()].num>=d+1){
			ans[a[i].id]=ans[a[q.top()].id];
			q.pop();
			q.push(i);
		}
		else{
			ans[a[i].id]=++tt;
			q.push(i);
		}
	}
	printf("%lld\n",tt);
	for(ll i=1;i<=n;i++){
		printf("%lld ",ans[i]);
	}
	puts("");
}

int main(void){
	scanf("%lld %lld %lld",&n,&m,&d);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i].num);
		a[i].id=i;
	}
	solve();
	return 0;
}
