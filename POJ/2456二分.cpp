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

int n,c;
int a[maxn];

bool check(int x){
	int now=a[1],sum=1;
	for(int i=2;i<=n;i++){
		if(a[i]-now>=x){
			now=a[i];
			sum++;
		}
	}
	if(sum>=c)
		return 1;
	return 0;
}

void solve(){
	sort(a+1,a+1+n);
	int L=0,R=1000000000,mid;
	while(L<R){
		mid=(L+R)>>1;
		if(check(mid)){
			L=mid+1;
		}
		else{
			R=mid;
		}
	}
	if(!check(L))
		L--;
	printf("%d\n",L);
}

int main(void){
	scanf("%d %d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
