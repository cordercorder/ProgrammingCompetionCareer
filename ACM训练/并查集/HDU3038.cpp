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

const int maxn=200000+100;
const ll maxw=INT_MAX+1;

ll sum[maxn];
ll n,m;
ll A,B,S;

bool check(){
	if(sum[B]==maxw&&sum[A-1]==maxw){
		sum[B]=S;
		sum[A-1]=0;
		return 1;
	}
	if(sum[B]!=maxw&&sum[A-1]==maxw){
		sum[A-1]=sum[B]-S;
		return 1;
	}
	if(sum[B]==maxw&&sum[A-1]!=maxw){
		sum[B]=sum[A-1]+S;
		return 1;
	}
	if(sum[B]!=maxw&&sum[A-1]!=maxw){
		if(sum[B]-sum[A-1]==S)
			return 1;
		return 0;
	}
}

int main(void){
	ll ans;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		for(ll i=0;i<=200000;i++)
			sum[i]=maxw;
		ans=0;
		for(ll i=0;i<m;i++){
			scanf("%lld %lld %lld",&A,&B,&S);
			if(check()){
				deb(sum[B]);
				deb(sum[A-1]);
				continue;
			}
			deb(sum[B]);
			deb(sum[A-1]);			
			
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
