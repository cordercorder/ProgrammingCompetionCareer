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
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
/*head------[@cordercorder]*/

const ll maxn=2e5+10;

pii p[maxn];
ll n;
vector<pii> res[maxn];
ll cnt;

bool cmp(const pii &a,const pii &b){
	return max(a.first,a.second)<max(b.first,b.second);
}

void solve(){
	cnt=0;
	sort(p+1,p+1+n,cmp);
	ll pre=0;
	for(ll i=1;i<=n;i++){
		if(pre!=max(p[i].first,p[i].second)){
			res[++cnt].push_back(p[i]);
		}
		else{
			res[cnt].push_back(p[i]);
		}
		pre=max(p[i].first,p[i].second);
	}
	
	
	
	
	
	
}


int main(void){
	FC;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;
	}
	
	solve();
	
	
	
	
	
	return 0;
}
