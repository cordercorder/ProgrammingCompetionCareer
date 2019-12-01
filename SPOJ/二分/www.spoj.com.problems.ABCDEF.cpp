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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e2+10;

int S[maxn];
int n;
int res[maxn*maxn],res2[maxn*maxn],cnt,ret[maxn*maxn*maxn],cnt2;

void handle(){
	cnt=1;
	cnt2=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			res[cnt]=S[i]+S[j];
			res2[cnt++]=S[i]*S[j]; 
		}
	}
	for(int i=1;i<cnt;i++){
		for(int j=1;j<=n;j++){
			if(S[j]==0)
				continue;
			ret[cnt2++]=res[i]*S[j];
		}
	}
	sort(ret+1,ret+cnt2);
}

void solve(){
	handle();
	int tmp,pos;
	int ans=0;
	for(int i=1;i<cnt;i++){
		for(int j=1;j<=n;j++){
			tmp=res2[i]+S[j];
			ans+=upper_bound(ret+1,ret+cnt2,tmp)-lower_bound(ret+1,ret+cnt2,tmp);	
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&S[i]);
		}
		solve();
	}
	return 0;
}
