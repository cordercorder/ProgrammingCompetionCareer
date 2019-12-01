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

const int maxn=1e5+10;

ll a[maxn],b[maxn];
ll n;

void solve(){
	sort(a+1,a+1+n,greater<ll>());
	sort(b+1,b+1+n,greater<ll>());
	ll ans1=0,ans2=0,ans;
	ll cnt=1;
	ll i,j;
	for(i=1,j=1;i<=n&&j<=n;){
		if(cnt&1){
			if(a[i]>b[j]){
				ans1+=a[i];
				i++;
			}
			else{
				j++;
			}
			
		}
		else{
			if(b[j]>a[i]){
				ans2+=b[j];
				j++;
			}
			else{
				i++;
			}
		}
		cnt++;
	}
	while(i<=n){
		if(cnt&1){
			ans1+=a[i];
		}
		cnt++;
		i++;
	}
	while(j<=n){
		if(cnt%2==0){
			ans2+=b[j];
		}
		cnt++;
		j++;
	}
	//deb(ans1);
	//deb(ans2);
	ans=ans1-ans2;
	cout<<ans;
}
 
int main(void){
	FC;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>b[i];
	}
	solve();
	return 0;
}
