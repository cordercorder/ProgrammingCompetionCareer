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
const long double eps=1e-4;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e3+10;

int n,k;
int a[maxn],b[maxn];

priority_queue<long double> q;

bool check(long double x){
	for(int i=1;i<=n;i++){
		q.push((long double)(a[i])-x*b[i]);
	}
	int cnt=0;
	long double sum=0;
	while(!q.empty()){
		sum+=(q.top());
		q.pop();
		cnt++;
		if(cnt==(n-k)){
			while(!q.empty())
				q.pop();
			if(sum>=0)
				return 1;
			else
				return 0;
		}
	}
	return 0;
}

void solve(){
	long double L=0,R=1,mid;
	while(abs(R-L)>=eps){
		mid=(L+R)/2;
		//deb(mid);
		if(check(mid)){
			L=mid;
		}
		else{
			R=mid;
		}
	}
	L=L*100;
	printf("%.0Lf\n",L);
}

int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		if(n==0&&k==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		solve();
	}
	return 0;
}
