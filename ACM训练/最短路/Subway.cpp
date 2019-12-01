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
const double maxw=1e30+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e2+10;

struct node{
	int x;
	int y;
	node(){}
	node(int xx,int yy):x(xx),y(yy){}
	void operator=(const node &a){
		this->x=a.x;
		this->y=a.y;
	}
};

struct E{
	int to;
	double w;
	bool operator<(const E &a)const{
		return w>a.w;
	}
	E(int _to,double _w):to(_to),w(_w){}
	E(){}
};

node st,ed;
node p[maxn];
int cnt;
int f[maxn];
vector<E> e[maxn];
double D[maxn];
bool isv[maxn];
priority_queue<E> q;

int Find(int x){
	return f[x]==-1?x:f[x]=Find(f[x]);
}

void Union(int x,int y){
	int nx=Find(x),ny=Find(y);
	if(nx==ny)
		return ;
	f[ny]=nx;
}

void handle(){
	int nx,ny;
	double tmp;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			if(i==j)
				continue;
			nx=Find(i);
			ny=Find(j);
			deb(i);
			deb(j);
			deb(nx);
			deb(ny);
			cout<<endl;
			
			
			tmp=sqrt((double)(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
			if(nx==ny){
				tmp/=(double)20*100/3;
				e[i].push_back(E(j,tmp));
			}
			else{
				tmp/=(double)5*100/3;
				e[i].push_back(E(j,tmp));
			}
		}
	}
}

void solve(int st){
	handle();
	for(int i=1;i<=cnt;i++){
		D[i]=maxw;
		isv[i]=0;
	}
	D[st]=(double)0;
	q.push(E(st,D[st]));
	E now;
	int u,v;
	double w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.to;
		if(isv[u])
			continue;
		isv[u]=1;
		for(int i=0;i<(int)e[u].size();i++){
			v=e[u][i].to;
			w=e[u][i].w;
			if(D[v]>D[u]+w){
				D[v]=D[u]+w;
				q.push(E(v,D[v]));
			}
		}
	}
	D[cnt]+=(double)0.5;
	cout<<(ll)D[cnt]<<endl;
}

int main(void){
	FC;
	int x,y,la=2;
	cnt=0;
	while(cin>>st.x>>st.y){
		memset(f,-1,sizeof(f));
		cin>>ed.x>>ed.y;
		p[++cnt]=st;
		while(cin>>x>>y){
			if(x==-1&&y==-1){
				la=cnt+1;
				continue;
			}
			p[++cnt]=node(x,y);
			Union(la,cnt);
		}
		p[++cnt]=ed;
		solve(1);
	}
	return 0;
}
