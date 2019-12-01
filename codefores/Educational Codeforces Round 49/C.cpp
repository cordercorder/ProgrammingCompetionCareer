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

int t;
int n;
int a[maxn];
int res[maxn],cnt;

void solve(){
	cnt=0;
	int x,y,ret;
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;){
		int j=i+1;
		while(j<=n&&a[i]==a[j]){
			j++;
		}
		ret=(j-i)>>1;
		while(ret){
			res[++cnt]=a[i];
			ret--;
		}
		i=j;
	}
	double tmp=1e4+10;
	for(int i=1;i<cnt;i++){
		if((double)(res[i])/res[i+1]<tmp){
			tmp=(double)(res[i])/res[i+1];
			x=res[i];
			y=res[i+1];
			if(tmp==1)
				break;
		}
	}
	printf("%d %d %d %d\n",x,x,y,y);
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
}
