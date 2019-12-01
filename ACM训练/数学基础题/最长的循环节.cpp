#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e3+10;

int n;
int ans[maxn];

int solve(int x){
	while(x%2==0){
		x/=2;
	}
	while(x%5==0){
		x/=5;
	}
	int sum;
	for(int i=1;i<=1000;i++){
		sum=1;
		for(int j=1;j<=i;j++){
			sum=(sum*10)%x;
		}
		if(sum%x==1){
			return i;
		}
	}
}

int main(void){
	int Max=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ans[i]=solve(i);
	}
	for(int i=1;i<=n;i++){
		if(ans[Max]<ans[i]){
			Max=i;
		}
	}
	printf("%d\n",Max);
	return 0;
}
