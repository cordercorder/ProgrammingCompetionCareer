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
typedef pair<int,int> pii;

const int maxn=2e4+10;

int t;
int n,cnt;
bool isv[maxn];
int res[maxn];
int Max[maxn];
int head[maxn]; 

struct E{
	int next;
	int to;
}edge[maxn<<1];

void Init_e(){
	cnt=0;
	memset(head,-1,sizeof(head));
	memset(isv,0,sizeof(isv));
}

void add(int u,int v){
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void solve(int x){
	isv[x]=1;
	res[x]=1;
	int u;
	Max[x]=0;
	for(int i=head[x];i!=-1;i=edge[i].next){
		u=edge[i].to;
		if(!isv[u]){
			solve(u);
			res[x]+=res[u];
			Max[x]=max(Max[x],res[u]);
		}
	}
	Max[x]=max(Max[x],n-res[x]);
}

int main(void){
	int u,v;
	int ans;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			Init_e();
			for(int i=0;i<n-1;i++){
				scanf("%d %d",&u,&v);
				add(u,v);
				add(v,u);
			}
			solve(1);
			u=1;
			ans=Max[u];
			for(int i=2;i<=n;i++){
				if(Max[i]<ans){
					ans=Max[i];
					u=i;
				}
			}
			printf("%d %d\n",u,ans);
		}
	}
	return 0;
}
