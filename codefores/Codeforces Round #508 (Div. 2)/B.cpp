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
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

int n;

void solve(){
	printf("Yes\n"); 
	printf("2 1 %d\n",n);
	printf("%d ",n-2);
	for(int i=2;i<n;i++){
		printf("%d ",i);
	}
}

int main(void){
	cin>>n;
	if(n==1||n==2){
		cout<<"No";
		return 0;
	}
	solve();
	return 0;
}
