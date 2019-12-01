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
	int ai;
	int ti;
	int id;
	bool operator<(const node &a)const{
		if(ti<a.ti)
			return 1;
		if(ti==a.ti&&id<a.id)
			return 1;
		return 0;
	}
};

int n,T;
vector<node> p[maxsize];
set<node> S;
set<node>::iterator it;

void solve(){
	int sum=0;
	for(int i=n;i>=0;i--){
		for(int j=0;j<p[i].size();j++){
			S.insert({p[i][j].ai,p[i][j].ti,p[i][j].id});
			sum=sum+p[i][j].ti;
		}
		//for(it=S.begin();it!=S.end();it++){
		//	printf("ai=%d  ti=%d  id=%d\n",it->ai,it->ti,it->id);	
		//}
		//printf("\n");
		while(S.size()>i){
			sum=sum-(--S.end())->ti;
			S.erase(--S.end());
		}
		if(S.size()==i&&sum<=T){
			break;
		}
	}
	printf("%d\n%d\n",S.size(),S.size());
	if(S.empty())
		return ;
	printf("%d",S.begin()->id);
	for(it=++S.begin();it!=S.end();it++){
		printf(" %d",it->id);
	}
	printf("\n");
}

int main(void){
	int a,b; 
	while(scanf("%d %d",&n,&T)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d %d",&a,&b);
			p[a].push_back({a,b,i+1});
		}
		solve();
		S.clear();
	}
	return 0;
}
