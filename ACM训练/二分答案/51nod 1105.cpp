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
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=5e4+10;

ll n,k;
ll a[maxn],b[maxn];

bool check(ll x){
	ll sum=0,tmp,pos;
	for(ll i=n;i>=1;i--){
		tmp=x/a[i]+(ll)(x%a[i]!=0);
		pos=upper_bound(b+1,b+1+n,tmp,greater<ll>())-b-1;
		sum+=pos;
	}
	return sum>=k;
}

void solve(){
	sort(a+1,a+1+n,greater<ll>());
	sort(b+1,b+1+n,greater<ll>());
	ll l=a[n]*b[n],r=a[1]*b[1],mid;
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
	cout<<l<<'\n';
}

int main(void){
	FC;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	solve();
	return 0;
}
