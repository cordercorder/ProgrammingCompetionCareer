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

const int maxn=1e5+10;

int h[maxn];
int n;
int sta[maxn],top;
int L[maxn],R[maxn];

void solve(){
	top=0;
	for(int i=1;i<=n;i++){
		while(top>0&&h[sta[top]]>=h[i]){
			--top;
		}
		if(top==0){
			L[i]=0;
		}
		else{
			L[i]=sta[top];
		}
		sta[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;i--){
		while(top>0&&h[sta[top]]>=h[i]){
			--top;
		}
		if(top==0){
			R[i]=n+1;
		}
		else{
			R[i]=sta[top];
		}
		sta[++top]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,(ll)(R[i]-L[i]-1)*h[i]);
	}
	printf("%lld\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
		}
		solve();
	}
	return 0;
}
