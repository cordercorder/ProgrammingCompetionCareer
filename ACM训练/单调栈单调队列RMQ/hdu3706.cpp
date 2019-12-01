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

const int maxn=1e7+10;

ll n,a,b;
int S[maxn];
int Q[maxn];

void solve(){
	ll front=0,back=0,tmp;
	tmp=1;
	for(ll i=1;i<=n;i++){
		tmp=tmp*a%b;
		S[i]=(int)tmp;
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
		if(front<back&&Q[front+1]<(i-a)){
			++front;
		}
		while(front<back&&S[Q[back]]>=S[i]){
			--back;
		}
		Q[++back]=i;
		ans=ans*(ll)S[Q[front+1]]%b;
	}
	printf("%lld\n",ans);
}

int main(void){
	while(scanf("%lld %lld %lld",&n,&a,&b)!=EOF){
		solve();
	}
	return 0;
}
