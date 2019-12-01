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

const ll maxn=5e2+10;

bool isv[maxn+maxn];
ll cnt;
vector<ll> e[maxn+maxn];

ll t;
ll n,s;
ll len;
ll linker[maxn+maxn];
bool f;

void pre_handle(){
	for(ll i=1;i<=n;i++){
		for(ll j=s+1,cnt=1;j<=s+n;j++,cnt++){
			if(j%i==0){
				e[i].push_back(cnt);
			}
		}
	}
}

bool dfs(ll u){
	ll v;
	for(ll i=0;i<(ll)e[u].size();i++){
		v=e[u][i];
		if(!isv[v]){
			isv[v]=1;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return 1;
			}
		}
	}
	return 0;
}

void solve(){
	ll sum=0;
	if(s<n){
		swap(n,s);
	}
	if(n>500){
		puts("No");
		f=1;
		return ;
	}
	pre_handle();
	memset(linker,-1,sizeof(linker));
	for(ll i=1;i<=n;i++){
		memset(isv,0,sizeof(isv));
		if(dfs(i)){
			sum++;
		}
	}
	if(sum==n){
		puts("Yes");
		return ;
	}
	puts("No");
}

int main(void){
	scanf("%lld",&t);
	for(ll ca=1;ca<=t;ca++){
		f=0;
		scanf("%lld %lld",&n,&s);
		printf("Case #%d: ",ca);
		solve();
		if(f)
			continue;
		for(ll i=1;i<=n;i++){
			if(e[i].empty())
				continue;;
			e[i].clear();
		}
	}
	return 0;
}
