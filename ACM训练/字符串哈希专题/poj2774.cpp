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

const int maxn=1e5+10;

char s[maxn],s2[maxn];
ull base[maxn],seed=131;
ull h[maxn];
int cnt,cnt2;

void pre_handle(){
	base[0]=1;
	for(int i=1;i<maxn;i++){
		base[i]=seed*base[i-1];
	}
}

bool check(int len){
	h[0]=0;
	for(int i=0;i<len;i++){
		h[0]=h[0]*seed+(ull)s[i];
	}
	for(int i=0;i+len<cnt;i++){
		h[i+1]=h[i]*seed-base[len]*(ull)s[i]+(ull)s[i+len];
	}
	sort(h,h+cnt-len+1);
	ull bhash=0;
	for(int i=0;i<len;i++){
		bhash=bhash*seed+(ull)s2[i];
	}
	if(binary_search(h,h+cnt-len+1,bhash))
		return true;
	for(int i=0;i+len<cnt2;i++){
		bhash=bhash*seed-base[len]*(ull)s2[i]+(ull)s2[i+len];
		if(binary_search(h,h+cnt-len+1,bhash))
			return true;
	}
	return false;
}

void solve(){
	cnt=strlen(s);
	cnt2=strlen(s2);
	int l=0,r=min(cnt,cnt2),mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	if(!check(l))
		l--;
	printf("%d\n",l);
}

int main(void){
	pre_handle();
	while(scanf("%s %s",s,s2)!=EOF){
		solve();
	}
	return 0;
}
