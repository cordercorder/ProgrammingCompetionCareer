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

const int maxn=3e5+10;

int a[maxn],sum[maxn];
int n,m;
int q[maxn];

void solve(){
	int front=0,back=0,ans=INT_MIN;
	q[++back]=0;
	for(int i=1;i<=n;i++){
		if(q[front+1]<i-m){
			++front;
		}
		while(front<back&&sum[q[back]]>=sum[i]){
			--back;
		}
		q[++back]=i;
		ans=max(ans,sum[q[back]]-sum[q[front+1]]);
	}
	printf("%d\n",ans);
}

int main(void){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	solve();
	return 0;
}
