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

const int maxn=20;

int n;
int w[maxn],v1[maxn],v2[maxn];
int q,r;
int dp1[1205],dp2[1205];
int ans;

int solve(int x){
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	for(int i=0;i<n;i++){
		if((x&(1<<i))){
			for(int j=w[i];j<=q;j++){
				dp1[j]=max(dp1[j],dp1[j-w[i]]+v1[i]);
			}
		}
		else{
			for(int j=w[i];j<=r;j++){
				dp2[j]=max(dp2[j],dp2[j-w[i]]+v2[i]);
			}
		} 
	}
	return dp1[q]+dp2[r];
}

int main(void){
	int len; 
	while(scanf("%d",&n)!=EOF){
		if(n==-1)
			break;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&w[i],&v1[i],&v2[i]);
		}
		scanf("%d %d",&q,&r);
		len=(1<<n);
		ans=0;
		for(int i=0;i<len;i++){
			ans=max(ans,solve(i));
		}
		printf("%d\n",ans);
	}
	return 0;
}
