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

const int maxn=1e5+10;

int n;
double x[maxn][7];

void solve(){
	int len=(1<<5);
	double tmp,sum,ans=-maxw,Min,Max;
	int ret;
	for(int tot=0;tot<len;tot++){
		ret=tot;
		Min=maxw;
		Max=-maxw;
		for(int i=1;i<=n;i++){
			sum=0;
			for(int j=0;j<5;j++){
				if(ret&(1<<j)){
					sum+=x[i][j];
				}
				else{
					sum-=x[i][j];
				}
			}
			if(Min>sum){
				Min=sum;
			}
			if(Max<sum){
				Max=sum;
			}
		}
		ans=max(ans,Max-Min);
	}
	printf("%.2lf\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=0;j<5;j++){
				scanf("%lf",&x[i][j]);
			}
		}
		solve();	
	}
	return 0;
}
