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

int n,k;
vector<int> ans,tmp;

void solve(){
	int l;
	ans.resize(10000);
	for(int i=1;i<=k+1;i++){
		int j=i;
		tmp.clear();
		while(j<=n){
			tmp.push_back(j);
			j=j+2*k+1;
		}
		if(j-k>n&&(int)tmp.size()<(int)ans.size()){
			//for(int i=0;i<(int)tmp.size();i++){
			//	cout<<tmp[i]<<" ";
			//}
			//cout<<endl;
			ans=tmp;
		}
	}
	cout<<(int)ans.size()<<'\n';
	for(int i=0;i<(int)ans.size();i++){
		cout<<ans[i]<<" ";
	}
}

int main(void){
	FC;
	cin>>n>>k;
	solve();
	return 0;
}
