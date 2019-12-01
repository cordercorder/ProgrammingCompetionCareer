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
const int maxw=1e8+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=20;

int t,m;
char name[maxn][105];
int d[maxn],c[maxn],ti[(1<<15)+10],dp[(1<<15)+10];
int n;
int pre[(1<<15)+10];

void print(int x){
	if(x==0)
		return ;
	print(x-(1<<pre[x]));
	printf("%s\n",name[pre[x]]);
}

void solve(){
	int len=(1<<n)-1;
	int tmp,cost;
	for(int i=1;i<=len;i++){
		dp[i]=maxw;
		for(int j=n-1;j>=0;j--){
			tmp=1<<j;
			if(!(tmp&i))
				continue;
			tmp=i-tmp;
			cost=ti[tmp]+c[j]-d[j];
			if(cost<0)
				cost=0;
			if(dp[i]>dp[tmp]+cost){
				dp[i]=dp[tmp]+cost;
				ti[i]=ti[tmp]+c[j];
				pre[i]=j;
			}
		}
	}
	printf("%d\n",dp[len]);
	print(len);
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s %d %d",name[i],&d[i],&c[i]);
			ti[i]=0;
		}
		solve();
	}
	return 0;
}
