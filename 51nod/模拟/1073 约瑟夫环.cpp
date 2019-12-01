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

const int maxn=1e6+10;

int n,k;
int dp[maxn];

int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		dp[1]=0;
		for(int i=2;i<=n;i++){
			dp[i]=(dp[i-1]+k)%i;//f[n,k]=(f[n-1,k]+k)%n  n>1   f[n,k]=0 n=1;
		}
		printf("%d\n",dp[n]+1);
	}
	return 0;
}
