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
const int maxw=3e8+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=5e2+10;

struct node{
	int from;
	int to;
	int w;
};

vector<node> e;
int n,m,res;
int t;
int D[maxn];


bool check(int st){
	for(int i=1;i<=n;i++){
		D[i]=maxw;
	}
	D[st]=0;
	int u,v,w;
	for(int i=1;i<n;i++){
		bool f=0;
		for(int j=0;j<(int)e.size();j++){
			u=e[j].from;
			v=e[j].to;
			w=e[j].w;
			if(D[v]>D[u]+w){
				D[v]=D[u]+w;
				f=1;
			}
		}
		if(!f){
			return 1;
		}
	}
	for(int i=0;i<(int)e.size();i++){
		u=e[i].from;
		v=e[i].to;
		w=e[i].w;
		if(D[v]>D[u]+w){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int u,v,w;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&res);
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&u,&v,&w);
			e.push_back({u,v,w});
			e.push_back({v,u,w});
		}
		for(int i=1;i<=res;i++){
			scanf("%d %d %d",&u,&v,&w);
			e.push_back({u,v,-w});
		}
		if(check(1)){
			puts("NO");
		}
		else{
			puts("YES");
		}
		e.clear();
	}
	return 0;
}
