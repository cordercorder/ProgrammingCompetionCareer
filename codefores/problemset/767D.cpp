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
typedef pair<ll,ll> pii;
/*head------[@cordercorder]*/

const ll maxn=1e6+10;

ll n,m,k;
ll f[maxn];
pii s[maxn];

bool cmp(const pii &a,const pii &b){
	return a.first>b.first;
}

bool check(ll x){
	ll i=1,j=min(x,m);
	ll now=0,sum=0;
	for(i=1;i<=n&&j>=(ll)1;){
		if(f[i]<=s[j].first){
			if(f[i]>=now){
				sum++;
				if(sum==k){
					sum=0;
					now++;
				}
				i++;
			}
			else{
				return 0;
			}
		}
		else{
			if(s[j].first>=now){
				sum++;
				if(sum==k){
					sum=0;
					now++;
				}
				j--;
			}
			else{
				return 0;
			}
		}
	}
	while(i<=n){
		if(f[i]>=now){
			sum++;
			if(sum==k){
				now++;
				sum=0;
			}
			i++;
		}
		else{
			return 0;
		}
	}
	while(j>=(ll)1){
		if(s[j].first>=now){
			sum++;
			if(sum==k){
				now++;
				sum=0;
			}
			j--;
		}
		else{
			return 0;
		}
	}
	return 1;
}

void solve(){
	sort(f+1,f+1+n);
	sort(s+1,s+1+m,cmp);
	ll now=0,sum=0;
	for(ll i=1;i<=n;i++){
		if(f[i]>=now){
			sum++;
			if(sum==k){
				sum=0;
				now++;
			}
		}
		else{
			puts("-1");
			return ;
		}
	}
	ll l=0,r=1e6+10,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	if(!check(l)){
		l--;
	}
	l=min(l,m);
	printf("%lld\n",l);
	for(ll i=1;i<=l;i++){
		if(i==1){
			printf("%lld",s[i].second);
			continue;
		}
		printf(" %lld",s[i].second);
	}
	puts("");
}

int main(void){
	//freopen("in.txt","r",stdin);
	//clock_t st=clock();
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&f[i]);
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld",&s[i].first);
		s[i].second=i;
	}
	solve();
	//clock_t ed=clock();
	//cout<<"running time is "<<(double)(ed-st)<<"ms"<<endl; 
	return 0;
}
