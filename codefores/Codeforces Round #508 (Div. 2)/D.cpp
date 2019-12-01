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
int num[30];

void solve(){
	for(int i=0;i<(int)s.length();i++){
		num[s[i]-'A']++;
	}
	int Min=1000000;
	for(int i=0;i<k;i++){
		//deb(num[i]);
		Min=min(Min,num[i]);
	}
	cout<<Min*k;
}

int main(void){
	FC;
	cin>>n>>k;
	cin>>s;
	solve();
	return 0;
}
