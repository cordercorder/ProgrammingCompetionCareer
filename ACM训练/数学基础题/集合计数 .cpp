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

ll t;
ll a,b,n;

ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll d=exgcd(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=tmp-a/b*y;
	return d;
}

void solve(){
	ll x,y,max_y,ans,ret;
	ll tmp=exgcd(a,b,x,y); 
	if((n+1LL)%tmp!=0){
		puts("0");
		return ;
	}
	x=x*(n+1LL)/tmp; 
	y=y*(n+1LL)/tmp;
	ret=b/tmp;
	x=(x%ret+ret)%ret;
	if(x==0)
		x+=ret;
	max_y=(n+1-x*a)/b;
	ret=a/tmp;
	y=(y%ret+ret)%ret;
	if(y==0){
		y+=ret;
	}
	//deb(max_y);
	//deb(y);
	ans=(max_y-y)/ret+1;
	cout<<ans<<endl;
}

int main(void){
	//FIN;
	//FOUT;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		solve();
	}
	return 0;
}
