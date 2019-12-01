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

ll n,m;

ll cal(){
	ll l=0,r=n*(n+1)/2,mid,ans;
	while(l<r){
		mid=(l+r)>>1;
		if(mid*(mid-1LL)/2LL>=m){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}

int main(void){
	FC;
	cin>>n>>m;
	if(m>=(n+1)/2){
		cout<<"0 "<<n-cal()<<'\n';
	}
	else{
		cout<<n-m*2LL<<" "<<n-cal()<<'\n';
	}
	return 0;
}
