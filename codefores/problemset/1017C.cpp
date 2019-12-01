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

int n;
vector<int> ans[maxn];

void solve(){
	int cnt=0;
	int len=sqrt(n);
	for(int i=1;i<=n;i++){
		ans[cnt].push_back(i);
		if(i%len==0){
			cnt++;
		}
	}
	for(int i=cnt;i>=0;i--){
		for(int j=0;j<(int)ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
	}
}

int main(void){
	FC;
	cin>>n;
	solve();
	return 0;
}
