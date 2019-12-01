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
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e9+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=1e2+10;

struct node{
	ll to;
	ll w;
	ll max_L;
	ll min_L;
	bool operator<(const node &a)const{
		return w>a.w;
	}
	node(){}
	node(ll a,ll b):to(a),w(b){}
	node(ll a,ll b,ll c,ll d):to(a),w(b),max_L(c),min_L(d){}
};

ll n,m;
ll P[maxn],L[maxn];
bool isv[maxn];
ll D[maxn];
priority_queue<node> q;
vector<node> e[maxn];

void handle(ll st){
	for(ll i=1;i<=n;i++){
		isv[i]=0;
		D[i]=maxw;
	}
	D[st]=P[st];
	q.push(node(st,D[st],L[st],L[st]));
	node now,tmp;
	ll u,v,w,max_L,min_L;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.to;
		if(isv[u])
			continue;
		isv[u]=1;
		max_L=now.max_L;
		min_L=now.min_L;
		for(ll i=0;i<(ll)e[u].size();i++){
			v=e[u][i].to;
			w=e[u][i].w;
			if(D[v]>D[u]+w&&L[v]<=L[1]+m&&L[v]>=L[1]-m&&L[v]>=max_L-m&&L[v]<=min_L+m){
				D[v]=D[u]+w;
				tmp.max_L=max(max_L,L[v]);
				tmp.min_L=min(min_L,L[v]);
				tmp.to=v;
				tmp.w=D[v];
				q.push(tmp);
			}
		}
	}
}

void solve(){
	ll ans=maxw;
	for(ll i=1;i<=n;i++){
		handle(i);
		ans=min(ans,D[1]);
		//deb(i);
		//deb(D[1]);
		//cout<<endl;
	}
	cout<<ans<<endl;
}

int main(void){
	FC;
	//FIN;
	ll x,T,V;
	while(cin>>m>>n){
		for(ll i=1;i<=n;i++){
			cin>>P[i]>>L[i]>>x;
			for(ll j=1;j<=x;j++){
				cin>>T>>V;
				e[T].push_back(node(i,V));
			}
		}
		solve();
		for(ll i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}
