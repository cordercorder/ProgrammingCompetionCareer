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
const int maxw=1e6+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=5e2+10;

int n,m,K;
char s[maxn][maxn];
vector<int> res[maxn];
int num[maxn][maxn],dp[maxn][maxn];

void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='1'){
				res[i].push_back(j);
			}
		}
	}
	int ret,tmp;
	for(int i=1;i<=n;i++){
		if(res[i].empty()){
			for(int j=0;j<=K;j++){
				num[i][j]=0;
			}
			continue;
		}
		for(int j=0;j<=m;j++){
			num[i][j]=maxw;
		}
		for(int j=0;j<(int)res[i].size();j++){
			for(int k=j;k<(int)res[i].size();k++){
				ret=(int)res[i].size()-(k-j+1);
				num[i][ret]=min(num[i][ret],res[i][k]-res[i][j]+1);
			}
		}
		num[i][(int)res[i].size()]=0; 
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=K;j++){
			dp[i][j]=maxw;
		}
	}
	memset(dp[0],0,sizeof(dp[0]));
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<=K;j++){
			printf("%d ",num[i][j]); 
		}
		puts("");
	}*/
	for(int i=1;i<=n;i++){
		for(int j=K;j>=0;j--){
			for(int k=0;k<=j;k++){
				dp[i][j]=min(dp[i][j],dp[i-1][j-k]+num[i][k]);
			}
		}
	}
	printf("%d\n",dp[n][K]);
}

int main(void){
	scanf("%d %d %d",&n,&m,&K);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	solve();
	return 0;
}
