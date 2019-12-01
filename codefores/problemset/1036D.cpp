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

const ll maxn=3e5+10;

ll a[maxn],b[maxn];
ll n,m;

void solve(){
	ll i=1,j=1,ans=0;
	ll sum1=a[i],sum2=b[j];
	while(i<=n&&j<=m){
		if(sum1==sum2){
			i++;
			j++;
			if(i<=n){
				sum1=a[i];
			}
			if(j<=m){
				sum2=b[j];
			}
			ans++;
		}
		else if(sum1>sum2){
			j++;
			sum2+=b[j];
		}
		else{
			i++;
			sum1+=a[i];
		}
	}
	if(i>n&&j>m&&sum1==sum2){
		cout<<ans;
	}
	else{
		cout<<"-1";
	}
}

int main(void){
	FC;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m; 
	for(ll i=1;i<=m;i++){
		cin>>b[i];
	}
	solve();
	return 0;
}
