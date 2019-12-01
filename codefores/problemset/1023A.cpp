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

int n,m;
string s,t;

void solve(){
	int pos=s.find('*');
	if(pos==string::npos){
		if(s==t)
			cout<<"YES"; 
		else
			cout<<"NO";
		return ;
	}
	for(int i=0;i<pos;i++){
		if(s[i]==t[i])
			continue;
		cout<<"NO";
		return ;
	}
	int i,j;
	for(i=(int)s.length()-1,j=(int)t.length()-1;i>pos&&j>=pos;i--,j--){
		if(s[i]==t[j]){
			continue;
		}
		cout<<"NO";
		return ;
	}
	if(i==pos){
		cout<<"YES";
		return ;
	}
	cout<<"NO";
}

int main(void){
	FC;
	cin>>n>>m;
	cin>>s>>t;
	solve();
	return 0;
}
