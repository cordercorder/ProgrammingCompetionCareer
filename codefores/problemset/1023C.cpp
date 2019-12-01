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
string s;
stack<int> sta;
map<int,int> mp;
map<int,int>::iterator it;
vector<int> ans;

void solve(){
	for(int i=0;i<(int)s.length();i++){
		if(!sta.empty()&&s[sta.top()]=='('&&s[i]==')'){
			mp[sta.top()]=i;
			sta.pop();
		}
		else{
			sta.push(i);
		}
	}
	int sum=0;
	int i;
	for(i=0;i<(int)s.length();i++){
		if(s[i]=='('){
			sum++;
			ans.push_back(i);
			ans.push_back(mp[i]);
			if(sum==k/2)
				break;
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<(int)ans.size();i++){
		cout<<s[ans[i]];
	}
}

int main(void){
	FC;
	cin>>n>>k>>s;
	solve();
	return 0;
}
