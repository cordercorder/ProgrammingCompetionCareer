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
const int maxw=-1e7;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2015+10;

int t,n;
int f[maxn];
int dp[maxn];

void solve(){
	int w=2*(n-1)-n;
	for(int i=1;i<=w;i++){
		dp[i]=maxw;
	}
	dp[0]=n*f[1];
	for(int i=1;i<n;i++){
		for(int j=i-1;j<=w;j++){
			dp[j]=max(dp[j],dp[j-i+1]+f[i]-f[1]);
		}
	}
	cout<<dp[w]<<'\n';
}

int main(void){
	FC;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<n;i++){
			cin>>f[i];
		}
		solve();
	}
	return 0;
}
