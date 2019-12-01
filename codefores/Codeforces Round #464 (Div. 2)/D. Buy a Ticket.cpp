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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=2e5+10;

struct node{
	ll adj;//邻接点 
	ll w;
	void Set(ll a,ll b);
	bool operator<(const node &a)const{
		if(w<a.w)
			return 1;
		if(w==a.w&&adj<a.adj)
			return 1;
		return 0;
	}
};

void node::Set(ll a,ll b){
	adj=a;
	w=b;
}

ll n,m;

ll a[maxsize];
ll D[maxsize];
vector<node> p[maxsize];
set<node> q; 

void solve(){
	ll i,u,v,w;
	node tmp;
	for(i=1;i<=n;i++){
		D[i]=a[i];
		tmp.Set(i,a[i]);
		q.insert(tmp);
	}
	while(!q.empty()){
		u=q.begin()->adj;
		//printf("###x=%lld\n",q.begin()->w);
		q.erase(q.begin());
		for(i=0;i<p[u].size();i++){
			v=p[u][i].adj;//u的邻接结点 
			w=p[u][i].w;//u的邻接边的权值 
			if(D[u]+w<D[v]){
				tmp.Set(v,D[v]);
				q.erase(tmp);
				D[v]=w+D[u];
				tmp.Set(v,D[v]);
				q.insert(tmp);
			}
		}
	}
	printf("%lld",D[1]);
	for(i=2;i<=n;i++)
		printf(" %lld",D[i]);
	printf("\n");
}

int main(void){
	ll i;
	ll u,v,w;
	node tmp; 
	scanf("%lld %lld",&n,&m);
	for(i=0;i<m;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		w=w*2;
		tmp.Set(v,w);
		p[u].push_back(tmp);
		tmp.Set(u,w);
		p[v].push_back(tmp);
	}
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	solve();
	return 0;
}
