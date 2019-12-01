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
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

ll n,k;

void solve(){
	ll res1=k/2+1;
	ll res2=k-res1;
	//deb(res1);
	//deb(res2);
	if(res1>=1&&res1<=n&&res2>=1&&res2<=n){
		cout<<min(res2,n-res1+(ll)1);
		return ;
	}
	cout<<"0";
}

int main(void){
	cin>>n>>k;
	solve();
	return 0;
}
