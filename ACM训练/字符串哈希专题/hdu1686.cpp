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

const ll mod[2]={1000000009LL,998244353LL};
string W,T;
int t;
ll seed=131LL,ret[2],tot[2],base[2];

void pre_handle(){
	ret[0]=0;
	ret[1]=0;
	for(ll i=0;i<(ll)W.size();i++){
		ret[0]=(ret[0]*seed+(ll)W[i])%mod[0];
		ret[1]=(ret[1]*seed+(ll)W[i])%mod[1];
	}
}

void solve(){
	int ans=0;
	tot[0]=0;
	tot[1]=0;
	base[0]=1;
	base[1]=1;
	pre_handle();
	int len=(int)W.size();
	for(ll i=0;i<len;i++){
		tot[0]=(tot[0]*seed+(ll)T[i])%mod[0];
		tot[1]=(tot[1]*seed+(ll)T[i])%mod[1];
		base[0]=(base[0]*seed)%mod[0];
		base[1]=(base[1]*seed)%mod[1];
	}
	if(tot[0]==ret[0]&&tot[1]==ret[1]){
		ans++;
	}
	//deb(tot[0]);
	//deb(tot[1]);
	for(ll i=0;i+len<(ll)T.size();i++){
		tot[0]=(tot[0]*seed-base[0]*(ll)T[i]+(ll)T[i+len])%mod[0];
		tot[0]=(tot[0]+mod[0])%mod[0];
		tot[1]=(tot[1]*seed-base[1]*(ll)T[i]+(ll)T[i+len])%mod[1];
		tot[1]=(tot[1]+mod[1])%mod[1];
		//deb(tot[0]);
		//deb(tot[1]);
		if(tot[0]==ret[0]&&tot[1]==ret[1]){
			ans++;
		}
	}
	cout<<ans<<'\n';
}

int main(void){
	FC;
	cin>>t;
	while(t--){
		cin>>W>>T;
		if((ll)W.size()>(ll)T.size()){
			cout<<"0"<<'\n'; 
		}
		solve();
	}
	return 0;
}
