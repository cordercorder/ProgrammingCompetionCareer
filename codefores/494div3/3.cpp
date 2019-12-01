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
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e3+10;

int n,k;
double a[maxn],sum[maxn],ans;

void solve(){
	ans=0;
	for(int i=1;i<=n-k+1;i++){
		for(int j=i+k-1;j<=n;j++){
			if(j-i+1>=k){
				ans=max(ans,(sum[j]-sum[i-1])/(j-i+1));
			}
		}
	}
	printf("%.9lf\n",ans);
}

int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%lf",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		solve();
	}
	return 0;
}
