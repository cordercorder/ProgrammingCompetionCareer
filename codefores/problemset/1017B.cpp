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

char s1[maxn],s2[maxn];
ll n;

void solve(){
	ll ans[4]={0,0,0,0};
	for(int i=1;i<=n;i++){
		if(s1[i]=='1'&&s2[i]=='1'){
			ans[0]++;
		}
		else if(s1[i]=='0'&&s2[i]=='0'){
			ans[1]++;
		}
		else if(s1[i]=='1'&&s2[i]=='0'){
			ans[2]++;
		}
		else if(s1[i]=='0'&&s2[i]=='1'){
			ans[3]++;
		}
	}
	cout<<(ans[0]*ans[1]+ans[2]*(ans[1]+ans[3]));
}

int main(void){
	FC;
	cin>>n>>(s1+1)>>(s2+1);
	solve();
	return 0;
}
