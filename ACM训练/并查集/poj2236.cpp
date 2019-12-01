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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1009;

int n,d;

struct node{
	int x;
	int y;
}point[maxn];

vector<int> res[maxn];
bool isv[maxn];
int pre[maxn];

int dis(node &a,node &b){
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void handle(){
	int tmp;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			tmp=dis(point[i],point[j]);
			if(tmp<=d*d){
				res[i].push_back(j);
				res[j].push_back(i);
			}
		}
	}
}

int Find(int x){
	if(pre[x]==-1)
		return x;
	return pre[x]=Find(pre[x]);
}

void Union(int x,int y){
	int nx=Find(x),ny=Find(y);
	if(nx!=ny){
		pre[nx]=ny;
	}
}

void solve(int x){
	int ret;
	isv[x]=true;
	for(int i=0;i<(int)res[x].size();i++){
		if(isv[res[x][i]]){
			ret=Find(res[x][i]);
			//pre[x]=ret;
			//deb(x);
			//deb(ret);
			//deb(res[x][i]);
			pre[ret]=x;
			//Union(x,res[x][i]);
		}
	}
}

int main(void){
	int p,q;
	char s[2];
	memset(pre,-1,sizeof(pre));
	scanf("%d %d",&n,&d);
	for(ll i=1;i<=n;i++){
		scanf("%d %d",&point[i].x,&point[i].y);
	}
	handle();
	while(scanf("%s",s)!=EOF){
		if(s[0]=='S'){
			scanf("%d %d",&p,&q);
			int np=Find(p),nq=Find(q);
			if(np==nq){
				printf("SUCCESS\n");
			}
			else{
				printf("FAIL\n");
			}
		}
		else{
			scanf("%d",&p);
			solve(p);
		}
	}
	return 0;
}
