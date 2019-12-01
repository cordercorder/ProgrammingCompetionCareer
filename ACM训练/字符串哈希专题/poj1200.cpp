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

string s;
int n,nc;
int res[1000+10];
bool isv[100000000+100];

void solve(){
	int cnt=0;
	for(int i=0;i<(int)s.length();i++){
		res[s[i]]=1;
	}
	for(int i=0;i<1010;i++){
		if(res[i]){
			res[i]=++cnt;
		}
	}
	int sum,ans=0;
	for(int i=0;i<(int)s.length()-n+1;i++){
		sum=0;
		for(int j=i;j<n+i;j++){
			sum=(sum*nc)+res[s[j]];
		}
		if(!isv[sum]){
			isv[sum]=1;
			ans++; 
		}
	}
	printf("%d\n",ans);
}

int main(void){
	FC;
	cin>>n>>nc;
	cin>>s;
	solve();
	return 0;
}
