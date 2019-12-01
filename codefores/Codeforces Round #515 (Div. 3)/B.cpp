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

const int maxn=1e3+10;

int n,r;
int a[maxn];
int res[maxn],cnt;

void solve(){
	int now=r;
	int ans=0;
	int pos;
	while(1){
		pos=upper_bound(res+1,res+1+cnt,now)-res-1;
		if(pos==0||now>=res[pos]+r-1+r){
			cout<<"-1"<<'\n';
			return;
		}
		//deb(res[pos]);
		now=res[pos]+r-1+r;
		ans++;
		if(res[pos]+r-1>=n)
			break;
		//deb(now);
	}
	cout<<ans<<'\n';
}

int main(void){
	FC;
	cin>>n>>r;
	cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			res[++cnt]=i;
		}
	}
	if(cnt==0){
		cout<<"-1"<<'\n';
		return 0;
	}
	solve();
	return 0;
}
