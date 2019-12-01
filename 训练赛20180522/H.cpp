# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const int maxn=1e5+10;
const int maxw=1e9+10;

ll n; 
vector<pii> p[maxn];
vector<ll> res;
ll in[maxn];
ll D[maxn];
priority_queue<pii,vector<pii>,greater<pii> > q;
bool isv[maxn];
map<ll,vector<ll> > mp;
ll num[maxn];

void solve(ll &ss){
	for(ll i=0;i<=n;i++){
		isv[i]=0;
		D[i]=maxw;
	}
	D[ss]=0;
	q.push({0,ss});
	pii now,tmp;
	ll u,v,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.second;
		if(isv[u])
			continue;
		for(ll i=0;i<(ll)p[u].size();i++){
			v=p[u][i].second;
			w=p[u][i].first;
			if(!isv[v]&&D[v]>D[u]+w){
				D[v]=D[u]+w;
				q.push({D[v],v});
			}	
		}
	}
	for(ll i=1;i<=n;i++){
		num[i]=max(num[i],D[i]);
	}
}

int main(void){
	ll u,v,w;
	ll ans;
	while(scanf("%lld",&n)!=EOF){
		memset(in,0,sizeof(in));
		memset(num,0,sizeof(num));
		for(ll i=0;i<n-1;i++){
			scanf("%lld %lld %lld",&u,&v,&w);
			p[u].push_back({w,v});
			p[v].push_back({w,u});
			in[v]++;
			in[u]++;
		}
		for(ll i=0;i<=n;i++){
			if(in[i]==1){
				res.push_back(i);
				//mp[i].resize(n+1);
				solve(i);
			}
		}
		ans=0;
		for(ll i=1;i<n;i++){
			ans+=num[i];
			//deb(num[i]);
			p[i].clear();
		}
		printf("%lld\n",ans);
		res.clear();
	}
	return 0;
}
