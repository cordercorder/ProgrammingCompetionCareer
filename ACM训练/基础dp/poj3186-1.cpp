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

int n;
int v[maxn];
int dp[maxn][maxn];

void solve(){
	for(int i=1;i<=n;i++){
		dp[i][i]=v[i]*n;
	}
	for(int k=1;k<n;k++){// the lenth of the segment
		for(int i=1;i+k<=n;i++){
			int j=i+k;
			dp[i][j]=max(dp[i+1][j]+v[i]*(n-k),dp[i][j-1]+v[j]*(n-k));
		}
	}
	printf("%d\n",dp[1][n]);
}

int main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	solve();
	return 0;
}
