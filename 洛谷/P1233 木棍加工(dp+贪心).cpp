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

# define ll long long

using namespace std;

struct node{
	int l;
	int w;
	bool operator <(const node &a)const{
		return this->l>a.l;
	}
};

const int maxsize=5e3+10;

node a[maxsize];
int dp[maxsize];
int n;

void solve(){
	int i,j,ans=0;
	for(i=0;i<n;i++){
		dp[i]=1;
		for(j=0;j<i;j++){
			if(a[i].w>a[j].w&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}

int main(void){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].l,&a[i].w);
	}
	sort(a,a+n);
	solve();
	return 0;
}
