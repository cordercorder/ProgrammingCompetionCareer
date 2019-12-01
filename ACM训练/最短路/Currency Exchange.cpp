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
const double maxw=1e9+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

struct node{
	int from;
	int to;
	double w;
	double co;
};

vector<node> e;
int n,m,s;
double ret;
double D[maxn];

bool check(int st){
	for(int i=1;i<=n;i++){
		D[i]=(double)0;
	}
	D[st]=ret;
	int u,v;
	double w;
	for(int i=1;i<n;i++){
		bool f=0;
		for(int j=0;j<(int)e.size();j++){
			u=e[j].from;
			v=e[j].to;
			w=(D[u]-e[j].co)*e[j].w;
			if(D[v]<w){
				D[v]=w;
				f=1;
			}
		}
		if(!f)
			return 1;//没有正环回路 
	}
	for(int i=0;i<(int)e.size();i++){
		if(D[e[i].to]<(D[e[i].from]-e[i].co)*e[i].w)
			return 0;//有正环回路 
	}
	return 1;//没有正环回路 
}

int main(void){
	int u,v;
	double w1,w2,co1,co2;
	scanf("%d %d %d %lf",&n,&m,&s,&ret);
	for(int i=0;i<m;i++){
		scanf("%d %d %lf %lf %lf %lf",&u,&v,&w1,&co1,&w2,&co2);
		e.push_back({u,v,w1,co1});
		e.push_back({v,u,w2,co2});
	}
	if(check(s)){
		puts("NO");
	}
	else{
		puts("YES");
	}
	return 0;
}
