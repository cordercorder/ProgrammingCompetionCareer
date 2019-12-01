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

const int maxn=1e3+10;

struct node{
	int st;
	int ed;
	int num;
}res[maxn];

int n,m,r;
int dp[maxn];

bool cmp(const node &a,const node &b){
	if(a.st<b.st)
		return 1;
	else if(a.st==b.st&&a.ed<b.ed)
		return 1;
	return 0;
}

void solve(){
	int ans=0;
	sort(res+1,res+1+m,cmp);
	for(int i=1;i<=m;i++){
		dp[i]=res[i].num;
		for(int j=1;j<i;j++){
			if(res[i].st>=res[j].ed){
				dp[i]=max(dp[i],dp[j]+res[i].num);
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}

int main(void){
	scanf("%d %d %d",&n,&m,&r);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&res[i].st,&res[i].ed,&res[i].num);
		res[i].ed+=r;
	}
	solve();
	return 0;
}
