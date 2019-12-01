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

const int maxn=1e5+10;

int n,m,k;
int q1[maxn],q2[maxn];//Max and Min 
int a[maxn];

void solve(){
	int front1=0,back1=0;
	int front2=0,back2=0;
	int pos=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		while(front1<back1&&a[q1[back1]]<a[i]){
			--back1;
		}
		while(front2<back2&&a[q2[back2]]>a[i]){
			--back2;
		}
		q1[++back1]=i;
		q2[++back2]=i;
		while(a[q1[front1+1]]-a[q2[front2+1]]>k){
			if(q1[front1+1]<q2[front2+1]){
				pos=q1[++front1];
			}
			else{
				pos=q2[++front2];
			}
		}
		if(a[q1[front1+1]]-a[q2[front2+1]]>=m){
			ans=max(ans,i-pos);
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d %d %d",&n,&m,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
}
