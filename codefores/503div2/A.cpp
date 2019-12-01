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


int n,h,a,b,k;
int ta,fa,tb,fb;

void solve(){
	if(ta==tb){
		printf("%d\n",abs(fa-fb));
		return ;
	}
	int ans=0;
	if(fa>=a&&fa<=b){
		ans+=abs(ta-tb)+abs(fa-fb);
		printf("%d\n",ans);
		return ;
	}
	ans=abs(fa-a)+abs(ta-tb)+abs(fb-a);
	ans=min(ans,abs(fa-b)+abs(ta-tb)+abs(fb-b));
	printf("%d\n",ans);
}

int main(void){
	scanf("%d %d %d %d %d",&n,&h,&a,&b,&k);
	for(int i=0;i<k;i++){
		scanf("%d %d %d %d",&ta,&fa,&tb,&fb);
		solve();
	}
	return 0;
}
