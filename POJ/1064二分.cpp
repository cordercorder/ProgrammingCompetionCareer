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
const long double eps=1e-10;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e4+10;

int n,k;
long double a[maxn];

bool check(long double x){
	int sum=0,tmp;
	for(int i=1;i<=n;i++){
		tmp=(a[i]/x);
		sum+=tmp;
	}
	//deb(sum);
	if(sum<k)
		return 0;
	return 1;
}

void solve(){
	long double L=0,R=1e5+10,mid;
	for(int i=0;i<=100;i++){
		mid=(L+R)/2;
		if(check(mid)){
			L=mid;
		}
		else{
			R=mid;
		}
	}
	long double ans=floor(L*100)/100;
	printf("%.2Lf\n",ans);
}

int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%Lf",&a[i]);
		}
		solve();
	}
	return 0;
}
