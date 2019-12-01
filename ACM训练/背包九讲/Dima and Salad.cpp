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

const int maxn=1e2+10;

int a[maxn],b[maxn],w[maxn];
int n,k;
int dp1[100000+100],dp2[100000+100];

void solve(){
	for(int i=1;i<=n;i++){
		w[i]=k*b[i]-a[i];
	}
	for(int i=1;i<=100000;i++){
		dp1[i]=maxw;
		dp2[i]=maxw;
	}
	dp1[0]=dp2[0]=0;
	for(int i=1;i<=n;i++){
		if(w[i]>=0){
			for(int j=100000;j>=w[i];j--){
				dp1[j]=max(dp1[j],dp1[j-w[i]]+a[i]);
			}
		}
		else{
			w[i]=-w[i];
			for(int j=100000;j>=w[i];j--){
				dp2[j]=max(dp2[j],dp2[j-w[i]]+a[i]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=100000;i++){
		ans=max(ans,dp1[i]+dp2[i]);
	}
	if(ans==0){
		cout<<"-1"<<endl;
		return;
	}
	cout<<ans<<endl;
}

int main(void){
	FC;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	solve();
	return 0;
}
