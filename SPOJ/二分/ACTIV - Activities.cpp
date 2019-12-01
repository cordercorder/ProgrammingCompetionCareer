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

const int maxn=1e5+10;

struct node{
	ll st;
	ll ed;
}res[maxn];

ll dp[maxn];
ll n;
ll sum[maxn];

bool cmp(const node &a,const node &b){
	return a.ed<b.ed;
}

void solve(){
	sort(res+1,res+1+n,cmp);
	ll pos;
	node tmp;
	sum[0]=0;
	for(ll i=1;i<=n;i++){
		tmp.ed=res[i].st;
		pos=upper_bound(res+1,res+1+n,tmp,cmp)-res;
		pos--;
		if(pos!=0&&res[pos].ed<=res[i].st){
			dp[i]+=sum[pos];
		}
		sum[i]=(sum[i-1]+dp[i])%100000000;
		//cout<<"dp[i]=="<<dp[i]<<endl;
	}
	printf("%08lld\n",sum[n]);
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		if(n==-1)
			break;
		for(ll i=1;i<=n;i++){
			scanf("%lld %lld",&res[i].st,&res[i].ed);
			dp[i]=1;
		}
		solve();
	}
	return 0;
}
