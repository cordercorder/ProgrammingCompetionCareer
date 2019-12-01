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

const int maxn=1e2+10;

int t;
int n;
char s[maxn];

void solve(){
	for(int i=1;i<=n;i++){
		if(i==(n-i+1))
			break;
		if(s[i]==s[n-i+1])
			continue; 
		if(s[i]-1==s[n-i+1]-1||s[i]-1==s[n-i+1]+1||s[i]+1==s[n-i+1]-1||s[i]+1==s[n-i+1]+1)
			continue;
		puts("NO");
		return ;
	}
	puts("YES");
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&n,s+1);
		solve();
	}
	return 0;
}
