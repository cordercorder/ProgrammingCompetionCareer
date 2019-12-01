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

const int maxn=1e3+10;

int n;
int a[maxn];
int b[maxn];

void solve(){
	sort(a+1,a+1+n);
	int res=0,ans=0;
	for(int i=1;i<=n;i++){
		b[i]=res;
		res+=a[i];
		ans+=res;
	//	deb(res); 
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
}
