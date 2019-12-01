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

const int maxn=2e5+10;

int a[maxn];
int n,m;
int res1,res2;
int sum[maxn];
map<int,int> mp;
int pos;

void solve(){
	res1=0,res2=0;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>m){
			res2++;
		}
		else if(a[i]<m){
			res1++;
		}
		sum[i]=(res2-res1);
	}
	for(int i=pos;i<=n;i++){
		mp[sum[i]]++;
	}
	ll ans=0;
	for(ll i=1;i<=pos;i++){
		ans+=(ll)(mp[sum[i-1]]);
		ans+=(ll)(mp[sum[i-1]+1]);
	}
	printf("%lld\n",ans);
}

int main(void){
	scanf("%d %d",&n,&m);
	pos=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==m){
			pos=i;
		}
	}
	if(pos==-1){
		puts("0");
		return 0;
	}
	solve();
	return 0;
}
