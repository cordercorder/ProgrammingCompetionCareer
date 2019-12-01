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
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=1e5+10;

char s[maxn],s2[maxn];
const ll mod[2]={1000000009LL,998244353LL};
ll seed=131LL;

void solve(){
	ll pre[2],suf[2],ret[2];
	suf[0]=0;
	suf[1]=0;
	pre[0]=0;
	pre[1]=0;
	ret[0]=1;
	ret[1]=1;
	int len=strlen(s),ans=len;
	for(int i=len-1;i>=0;i--){
		suf[0]=((suf[0]*seed)%mod[0]+(ll)s[i])%mod[0];
		suf[1]=((suf[1]*seed)%mod[1]+(ll)s[i])%mod[1];
		pre[0]=(pre[0]+ret[0]*(ll)s[i])%mod[0];
		pre[1]=(pre[1]+ret[1]*(ll)s[i])%mod[1];
		ret[0]=(ret[0]*seed)%mod[0];
		ret[1]=(ret[1]*seed)%mod[1];
		if(suf[0]==pre[0]&&suf[1]==pre[1]){
			ans=min(ans,i);
		}
	}
//	deb(ans);
	for(int j=0;j<len;j++){
		putchar(s[j]);
	}
	for(int j=ans-1;j>=0;j--){
		putchar(s[j]);
	}
	putchar('\n');
	return ;
}

int main(void){
	while(scanf("%s",s)!=EOF){
		solve();
	}
	return 0;
}
