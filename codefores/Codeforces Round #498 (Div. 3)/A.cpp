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

const int maxn=1e3+10;

int a[maxn];
int n;

void solve(){
	for(int i=1;i<=n;i++){
		if(a[i]&1)
			continue;
		a[i]--;
	}
	printf("%d",a[1]);
	for(int i=2;i<=n;i++){
		printf(" %d",a[i]);
	}
	printf("\n");
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
