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

int n,q;
int a[maxn];
int res[32];

void handle(int x){
	int tmp;
	for(int i=30;i>=0&&x>0;i--){
		tmp=(1<<i);
		if(x>=tmp){
			res[i]++;
			x-=tmp;
		}
	}
}

void solve(int x){
	int tmp,cnt,ans=0;
	for(int i=30;i>=0&&x>0;i--){
		tmp=(1<<i);
		cnt=min(x/tmp,res[i]);
		x-=cnt*tmp;
		ans+=cnt;
	}
	if(x>0){
		puts("-1");
		return ;
	}
	printf("%d\n",ans);
}

int main(void){
	int b;
	while(scanf("%d %d",&n,&q)!=EOF){
		memset(res,0,sizeof(res));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			handle(a[i]);
		}
		while(q--){
			scanf("%d",&b);
			solve(b);
		}
	}
	return 0;
}
