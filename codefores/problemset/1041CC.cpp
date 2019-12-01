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

struct node{
	ll num;
	ll tt;
	bool operator<(const node &a)const{
		if(num<a.num)
			return 1;
		else if(num==a.num&&tt<a.tt)
			return 1;
		return 0;
	}
	node(){}
	node(ll a,ll b):num(a),tt(b){}
	void operator=(const node &a){
		num=a.num;
		tt=a.tt;
	}
};

ll n,m,d;
set<node> res;
set<node>::iterator it;
ll ans[maxn];

void solve(){
	node now,tmp;
	tmp.tt=maxn;
	ll cnt=0;
	while(!res.empty()){
		now=*res.begin();
		res.erase(res.begin());
		ans[now.tt]=++cnt;
		tmp.num=now.num+d;
		while(1){
			it=res.upper_bound(tmp);
			if(it==res.end()){
				break;
			}
			tmp.num=it->num+d;
			ans[it->tt]=cnt;
			res.erase(it);
		}
	}
	printf("%lld\n",cnt);
	for(ll i=1;i<=n;i++){
		printf("%lld ",ans[i]);
	}
	puts("");
}

int main(void){
	ll x;
	scanf("%lld %lld %lld",&n,&m,&d);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&x);
		res.insert(node(x,i));
	}
	solve();	
	return 0;
}
