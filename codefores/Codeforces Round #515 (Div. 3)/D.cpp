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

const ll maxn=2e5+10;

ll n,m,k;
ll a[maxn];
ll sum[maxn];

void solve(){
	ll ans=0;
	ll res=k,cnt=1;
	for(ll i=1;i<=m;i++){
		sum[i]=k;
	}
	for(ll i=n;i>=1;i--){
		if(sum[cnt]<a[i]){
			cnt++;
			if(cnt>m)
				break;
			else{
				sum[cnt]-=a[i];
				ans++;
			}
		}
		else{
			ans++;
			sum[cnt]-=a[i];
		}
		/*for(ll i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
		cout<<endl;*/
	}
	cout<<ans<<'\n';
}

int main(void){
	FC;
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	solve();
	return 0;
}
