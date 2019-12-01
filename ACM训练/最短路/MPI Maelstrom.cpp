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

const ll maxn=1e2+10;

struct node{
	ll to;
	ll w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
};

priority_queue<node> q;
vector<node> e[maxn];

ll n;
char w[100];
ll a[maxn][maxn];
ll D[maxn];
bool isv[maxn];

ll cal(){
	ll ans=0,ret=1;
	ll len=strlen(w+1);
	if(w[1]=='x')
		return maxw;
	for(ll i=len;i>=1;i--){
		ans+=((ll)(w[i]-'0')*ret);
		ret*=10;
	}
	return ans;
}

void handle(){
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			if(a[i][j]==maxw)
				continue;
			e[i].push_back({j,a[i][j]});
			e[j].push_back({i,a[i][j]});
		}
	}
}

void solve(ll st){
	handle();
	for(ll i=1;i<=n;i++){
		D[i]=maxw;
		isv[i]=0;
	}
	D[st]=0;
	q.push({st,D[st]});
	node now;
	ll u,v,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.to;
		if(isv[u])
			continue;
		isv[u]=1;
		for(ll i=0;i<(ll)e[u].size();i++){
			v=e[u][i].to;
			w=e[u][i].w;
			if(D[v]>D[u]+w){
				D[v]=D[u]+w;
				q.push({v,D[v]});
			}
		}
	}
	printf("%lld\n",*max_element(D+1,D+1+n));
}

int main(void){
	ll tmp;
	scanf("%lld",&n);
	for(ll i=2;i<=n;i++){
		ll j;
		for(j=1;j<i;j++){
			scanf("%s",w+1);
			tmp=cal();
			a[i][j]=tmp;
		}
	}
	solve((ll)1);
	return 0;
}
