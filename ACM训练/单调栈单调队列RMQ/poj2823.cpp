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
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e6+10;

int n,a[maxn],k;
int Q[maxn];
int ans1[maxn],ans2[maxn];

void solve(){
	int front=0,back=0,cnt=1;
	for(int i=1;i<=k;i++){
		while(front<back&&a[Q[back]]>=a[i]){
			--back;
		}
		Q[++back]=i;
	}
	ans1[1]=a[Q[front+1]];
	for(int i=k+1;i<=n;i++){
		if(front<back&&Q[front+1]<i-k+1){
			++front;
		}
		while(front<back&&a[Q[back]]>=a[i]){
			--back;
		}
		Q[++back]=i;
		ans1[++cnt]=a[Q[front+1]];
	}
	front=0,back=0;
	cnt=1;
	for(int i=1;i<=k;i++){
		while(front<back&&a[Q[back]]<=a[i]){
			--back;
		}
		Q[++back]=i;
	}
	ans2[1]=a[Q[front+1]];
	for(int i=k+1;i<=n;i++){
		if(front<back&&Q[front+1]<i-k+1){
			++front;
		}
		while(front<back&&a[Q[back]]<=a[i]){
			--back;
		}
		Q[++back]=i;
		ans2[++cnt]=a[Q[front+1]];
	}
	printf("%d",ans1[1]);
	for(int i=2;i<=cnt;i++){
		printf(" %d",ans1[i]);
	}
	printf("\n%d",ans2[1]);
	for(int i=2;i<=cnt;i++){
		printf(" %d",ans2[i]);
	}
	printf("\n");
}

int main(void){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
