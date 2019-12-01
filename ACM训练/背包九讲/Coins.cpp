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

int n,m;
int a[maxn],c[maxn];
bool dp[100010+10];
int w[32*100];
int cnt;

void handle(int a,int b){
	int ret=1;
	while(b){
		if(b>=ret){
			w[++cnt]=a*ret;
			b-=ret;
			ret<<=1;
		}
		else{
			w[++cnt]=a*b;
			b=0;
		}
	}
}

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=cnt;i++){
		for(int j=m;j>=w[i];j--){
			dp[j]=dp[j]|dp[j-w[i]];
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(dp[i]){
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int tmp;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0&&m==0){
			break;
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&tmp);
			handle(a[i],tmp);
		}
		solve();
	}
	return 0;
}
