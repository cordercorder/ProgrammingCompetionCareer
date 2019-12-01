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
const int maxw=1e7+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e5+10;

vector<int> e[maxn];
int n;
int c[maxn],a[maxn],in[maxn];
bool isv[maxn];
int ret;
queue<int> q;

void dfs(int x){
	ret=min(ret,c[x]);
	isv[x]=1;
	int u;
	for(int i=0;i<(int)e[x].size();i++){
		u=e[x][i];
		if(!isv[u]){
			dfs(u);
		}
	}
}

void solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	int now,u;
	while(!q.empty()){
		now=q.front();
		q.pop();
		for(int i=0;i<(int)e[now].size();i++){
			u=e[now][i];
			in[u]--;
			e[now].erase(e[now].begin()+i);
			if(in[u]==0){
				q.push(u);
			}
		}
	}	
	for(int i=1;i<=n;i++){
		if(!isv[i]&&!e[i].empty()){
			ret=maxw;
			dfs(i);
			ans+=ret;
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int u;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&u);
		e[i].push_back(u);
		in[u]++;
	}
	solve();
	return 0;
}
