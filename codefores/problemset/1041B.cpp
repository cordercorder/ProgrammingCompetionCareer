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

ll a,b,x,y;

void solve(){
	ll tmp=__gcd(x,y);
	x/=tmp;
	y/=tmp;
	if(a<x||b<y){
		cout<<"0"<<'\n';
		return ;
	}
	ll ans1=a/x,ans2=b/y;
	cout<<min(ans1,ans2)<<'\n';
}

int main(void){
	FC;
	while(cin>>a>>b>>x>>y){
		solve();
	}
	return 0;
}
