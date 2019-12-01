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
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e3+10;

int s[maxn],d[maxn];
int n,k;
int dp[maxn];

void solve(){
	dp[1]=s[1];
	for(int i=2;i<=k;i++){
		dp[i]=min(dp[i-1]+s[i],dp[i-2]+d[i-1]);
	}
	int hh,mm,ss;
	ss=dp[k]%60;
	dp[k]-=ss;
	mm=(dp[k]/60)%60;
	dp[k]-=(mm*60);
	hh=dp[k]/3600+8;
	printf("%02d:%02d:%02d am\n",hh,mm,ss);
}

int main(void){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		for(int i=1;i<=k;i++) 
			scanf("%d",&s[i]);
		for(int i=1;i<k;i++)
			scanf("%d",&d[i]);
		solve();
	}
	return 0;
}
