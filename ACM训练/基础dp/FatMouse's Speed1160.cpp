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

typedef long long ll;

using namespace std;

const int maxn=1e3+10;

struct node{
	int w;
	int p;
	int id; 
}a[maxn];

int cnt; 
pair<int,int> dp[maxn];
vector<int> p;

bool cmp(const node &a,const node &b){
	if(a.w<b.w)
		return 1;
	else if(a.w==b.w&&a.p>b.p)
		return 1;
	return 0;
}

void solve(){
	for(int i=1;i<cnt;i++){
		dp[i].first=1;
		dp[i].second=i;
		for(int j=1;j<i;j++){
			if(a[j].p>a[i].p&&a[j].w<a[i].w&&dp[j].first+1>dp[i].first){
				dp[i].first=dp[j].first+1;
				dp[i].second=j;
			}
		}
	}
	int Max=0,ans=0;
	for(int i=1;i<cnt;i++){
		if(dp[i].first>Max){
			Max=dp[i].first;
			ans=i;
		}
	}
	printf("%d\n",Max);
	while(ans!=dp[ans].second){
		//printf("%d\n",a[ans].id);
		p.push_back(a[ans].id);
		ans=dp[ans].second;
	}
	p.push_back(a[ans].id);
	for(int i=p.size()-1;i>=0;i--){
		printf("%d\n",p[i]);
	}
	p.clear();
}

int main(void){
	cnt=1;
	node tmp;
	while(scanf("%d %d",&tmp.w,&tmp.p)!=EOF){
		tmp.id=cnt;
		a[cnt++]=tmp;
		sort(a+1,a+cnt,cmp);
	}
	solve();
	return 0;
}
