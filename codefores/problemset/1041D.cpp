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

const ll maxn=2e5+10;

ll n,h; 
ll x1[maxn],x2[maxn];
ll d[maxn],sum[maxn];

void solve(){
	ll ans=0,pos,tmp;
	for(ll i=1;i<n;i++){
		pos=lower_bound(sum+i,sum+n,sum[i-1]+h)-sum;
		tmp=d[pos]-d[i-1]+h;
		ans=max(ans,tmp);
	}
	tmp=x2[n]-x1[n]+h;
	ans=max(ans,tmp);
	cout<<ans<<'\n';
}

int main(void){
	FC;
	cin>>n>>h;
	d[0]=0;
	sum[0]=0;
	for(ll i=1;i<=n;i++){
		cin>>x1[i]>>x2[i];
		d[i]=d[i-1]+x2[i]-x1[i];
	}
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+x1[i+1]-x2[i];
	}	
	sum[n]=0;
	solve();
	return 0;
}
