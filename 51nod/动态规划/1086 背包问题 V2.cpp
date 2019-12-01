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

const int maxn=2e3+10;

int w[maxn],p[maxn],c[maxn];
int N,W;
int dp[50000+10];
int cnt;
int tmp1,tmp2,tmp3;

void handle(int &x){
	int m=x,res=1;
	while(m>0){
		if(m>=res){
			w[cnt]=res*tmp1;
			p[cnt++]=res*tmp2;
			m-=res;
			res<<=1;
		}
		else{
			w[cnt]=m*tmp1;
			p[cnt++]=m*tmp2;
			m=0;
		}
	}
}

void solve(){
	for(int i=1;i<cnt;i++){
		for(int j=W;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
		}
	}
	printf("%d\n",dp[W]);
}

int main(void){
	while(scanf("%d %d",&N,&W)!=EOF){
		cnt=1;
		for(int i=1;i<=N;i++){
			scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
			handle(tmp3);
		}
		//deb(cnt);
		solve();
	}
	return 0;
}
