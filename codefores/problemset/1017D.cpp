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

const int maxn=1e2+10;

int n,m,q;
int w[maxn];
int res[(1<<12)+100],sum[(1<<12)+100];
char tmp[20],t[20];
int k;
int dp[(1<<12)+100][110],len;

int cal(char *str){
	int ans=0;
	for(int i=0;str[i]!='\0';i++){
		ans=ans*2+(int)(str[i]-'0');
	}
	return ans;
}

void handle(){
	len=(1<<n);
	for(int i=0;i<len;i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				continue;
			}
			sum[i]+=w[j];
			sum[i]=min(sum[i],101);
		}
	}
}

void solve(int ret){
	int ans=0; 
	for(int i=0;i<len;i++){
		if(sum[ret^i]<=k){
			ans+=res[i];
		}
	}
	dp[ret][k]=ans;
}

int main(void){
	FC;
	int ret;
	cin>>n>>m>>q;
	//scanf("%d %d %d",&n,&m,&q);
	for(int i=n-1;i>=0;i--){
		cin>>w[i];
		//scanf("%d",&w[i]);
	}
	handle();
	for(int i=1;i<=m;i++){
		cin>>tmp;
		//scanf("%s",tmp);
		++res[cal(tmp)];
	}
	memset(dp,-1,sizeof(dp));
	while(q--){
		cin>>t>>k;
		//scanf("%s %d",&t,&k);
		ret=cal(t);
		if(dp[ret][k]==-1){
			solve(ret);
		}
		cout<<dp[ret][k]<<'\n';
		cout<<dp[ret][k]<<endl;
		//printf("%d\n",dp[ret][k]);
	}
	return 0;
}
