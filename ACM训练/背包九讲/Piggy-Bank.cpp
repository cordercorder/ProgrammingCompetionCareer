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
const int maxw=1e8+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=500+10;

int t;
int E,F,n;
int p[maxn],w[maxn];
int dp[10000+100];

void solve(){
	int res=F-E;
	for(int i=1;i<=res;i++){
		dp[i]=maxw;
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=w[i];j<=res;j++){
			dp[j]=min(dp[j],dp[j-w[i]]+p[i]);//dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+val[i])
		}
	}
	if(dp[res]==maxw){
		cout<<"This is impossible."<<'\n';
	}
	else{
		cout<<"The minimum amount of money in the piggy-bank is "<<dp[res]<<"."<<'\n';
	}
}

int main(void){
	FC;
	cin>>t;
	while(t--){
		cin>>E>>F>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i]>>w[i];
		}
		solve();
	}
	return 0;
}
