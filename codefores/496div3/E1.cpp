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

int n,m;
int p[maxn],sum[maxn],cnt;
int pos;
map<int,int> mp;

void handle(){
	int less=0,greater=0;
	for(int i=1;i<=n;i++){
		if(p[i]<m){
			less++;
		}
		else if(p[i]>m){
			greater++;
		}
		sum[i]=greater-less;
	}
}

void solve(){
	handle();
	for(int i=0;i<pos;i++){
		mp[sum[i]]++;
	}
	ll ans=0;
	for(int i=pos;i<=n;i++){
		ans+=mp[sum[i]];
		ans+=mp[sum[i]-1];
		//deb(i);
		//deb(ans);
		//cout<<endl;
	}
	printf("%lld\n",ans);
	mp.clear();
}

int main(void){
	while(scanf("%d %d",&n,&m)!=EOF){
		pos=-1;
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			if(p[i]==m){
				pos=i;
			}
		}
		if(pos==-1){
			puts("0");
			continue;
		}
		solve();
	}
	return 0;
}
