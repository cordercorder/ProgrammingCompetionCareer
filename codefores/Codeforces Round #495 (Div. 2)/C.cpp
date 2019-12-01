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

const int maxn=1e5+10;

int n;
int a[maxn];
set<int> s;
int res[maxn];
bool isv[maxn];

void solve(){
	ll ans=0;
	for(int i=n;i>=1;i--){
		s.insert(a[i]);
		res[i]=(int)s.size();
	}
	for(int i=1;i<=n-1;i++){
		if(isv[a[i]])
			continue;
		isv[a[i]]=1;
		ans+=(ll)res[i+1];
		//deb(res[i+1]);
	}
	printf("%lld\n",ans);	
}

int main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
