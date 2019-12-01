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

const int maxn=1e5+10;

ll n;
ll a[maxn];
ll L[maxn],R[maxn];
ll sum[maxn];
stack<ll> s;

struct node{
	ll l;
	ll r;
	ll data;
}res[maxn];

void handle(){
	for(ll i=1;i<=n;i++){
		while(!s.empty()&&a[s.top()]>=a[i]){
			s.pop();
		}
		if(s.empty()){
			L[i]=0;
		}
		else{
			L[i]=s.top();
		}
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	for(ll i=n;i>=1;i--){
		while(!s.empty()&&a[s.top()]>=a[i]){
			s.pop();
		}
		if(s.empty()){
			R[i]=n+1;
		}
		else{
			R[i]=s.top();
		}
		s.push(i);
	}
	while(!s.empty())
		s.pop();
}

bool cmp(const node &a,const node &b){
	return a.data>b.data;
}

void solve(){
	node tmp;
	for(int i=1;i<=n;i++){
		tmp.l=L[i]+1;
		tmp.r=R[i]-1;
		tmp.data=(sum[R[i]-1]-sum[L[i]])*a[i];
		res[i]=tmp;
	}
	sort(res+1,res+1+n,cmp);
	printf("%lld\n",res[1].data);
	printf("%lld %lld\n",res[1].l,res[1].r);
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		sum[0]=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		handle();
		solve();
	}
	return 0;
}
