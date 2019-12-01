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

ll q;
ll n,m,k;

void solve(){
	ll sum;
	if(n<m){
		swap(n,m);
	}
	if(k<n){
		cout<<"-1"<<'\n';
		return ;
	}
	if((n-m)&1){
		k--;
	}
	else if((k-n)&1){
		k-=2;
	}
	cout<<k<<'\n';
}

int main(void){
	FC;
	cin>>q;
	while(q--){
		cin>>n>>m>>k;
		solve();
	}
	return 0;
}
