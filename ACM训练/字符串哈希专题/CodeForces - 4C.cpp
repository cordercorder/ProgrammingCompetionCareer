#include<unordered_map>
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

int n;
unordered_map<string,int> mp;
string s;

int main(void){
	FC;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(mp.count(s)==0){
			mp[s]++;
			cout<<"OK"<<'\n';
		}
		else{
			cout<<s+to_string(mp[s])<<'\n';
			mp[s]++;
		}
	}
	return 0;
}
