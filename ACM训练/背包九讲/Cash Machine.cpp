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

const int maxn=200;

int S,n;
int cnt;
int v[maxn];
bool dp[100000+100];

void handle(int a,int b){
	int res=1;
	while(b){
		if(b>=res){
			v[++cnt]=a*res;
			b-=res;
			res<<=1;
		}
		else{
			v[++cnt]=a*b;
			b=0;
		}
	}
}

void solve(){
	memset(dp,false,sizeof(dp));
	dp[0]=true;
	for(int i=1;i<=cnt;i++){
		for(int j=S;j>=v[i];j--){
			dp[j]=dp[j]|(dp[j-v[i]]);
		}
	}
	for(int i=S;i>=0;i--){
		if(dp[i]){
			printf("%d\n",i);
			return ;
		}
	}
}

int main(void){
	int a,d;
	while(scanf("%d %d",&S,&n)!=EOF){
		cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a,&d);
			handle(d,a);
		}
		solve();
	}
	return 0;
}
