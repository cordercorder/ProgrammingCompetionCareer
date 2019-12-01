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
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e5+10;

ll n,q;
ll x;
ll res[32];

void solve(){
	ll tmp,ans=0;
	for(ll i=31;i>=0;i--){
		tmp=min(x/((ll)1<<i),res[i]);
		x-=tmp*(ll)1<<i;
		ans+=tmp;
	}
	if(x==0){
		printf("%lld\n",ans);
	}
	else{
		puts("-1");
	}
}

int main(void){
	ll tmp,num;
	while(scanf("%lld %lld",&n,&q)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&tmp);
			num=0;
			while(tmp){
				tmp>>=1;
				num++;
			}
			res[num]++;
			deb(num);
			deb(res[num]);
		}
		while(q--){
			scanf("%lld",&x);
			solve();
		}
	}
	return 0;
}
