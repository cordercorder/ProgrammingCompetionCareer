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

int n,m;
int c[maxn];
queue<int> q;

void solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(q.front()>=c[i]){
			q.pop();
			ans++;
		}
		if(q.empty())
			break;
	}
	printf("%d\n",ans);
}

int main(void){
	int x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		q.push(x);
	}
	solve();
	return 0;
}
