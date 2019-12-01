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
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

int t,n;
double w;
int m[maxn],sum;
double p[maxn];
double dp[10000+100];

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=m[i];j--){
			dp[j]=max(dp[j],dp[j-m[i]]*((double)1-p[i]));
		}
	}
	for(int i=sum;i>=0;i--){
		if(((double)1-dp[i])<w){
			cout<<i<<'\n';
			return ;
		}
	}
}

int main(void){
	FC;
	cin>>t;
	while(t--){
		cin>>w>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>m[i]>>p[i];
			sum+=m[i];
		}
		solve();
	}
	return 0;
}
