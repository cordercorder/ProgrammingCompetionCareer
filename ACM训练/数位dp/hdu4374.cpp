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
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

int t;
int a,b;
int tmp[15],cnt;
int dp[11][9999];

void bits(int x){
	cnt=0;
	while(x){
		tmp[++cnt]=x%10;
		x/=10;
	}
}

int dfs(int pos,int sum,bool f){
	if(pos==0){
		return sum>=0;
	}
	if(sum<0)
		return 0;
	if(!f&&dp[pos][sum]!=-1)
		return dp[pos][sum]; 
	int num;
	if(f){
		num=tmp[pos];
	}
	else{
		num=9;
	}
	int ans=0;
	for(int i=0;i<=num;i++){
		ans+=dfs(pos-1,sum-i*(1<<(pos-1)),f&&i==num);
	}
	if(!f){
		dp[pos][sum]=ans;
	}
	return ans;
}

void solve(){
	bits(b);
	int res=0,ret=1;
	while(a){
		res+=(a%10)*ret;
		a/=10;
		ret*=2;	
	}
	printf("%d\n",dfs(cnt,res,1));
}

int main(void){
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	for(int ca=1;ca<=t;ca++){
		scanf("%d %d",&a,&b);
		printf("Case #%d: ",ca);
		solve();
	}
	return 0;
}
