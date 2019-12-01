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

const int maxn=2e5+10;

int q;
char s[10];
int id;
int res[maxn],front,back,ans;

int main(void){
	FC;
	cin>>q;
	front=0;
	back=0;	
	while(q--){
		cin>>s>>id;
		if(s[0]=='L'){
			res[id]=--front;
		}
		else if(s[0]=='R'){
			res[id]=++back;
		}
		else{
			if(res[id]<0){
				ans=min(res[id]-front,back-res[id]-1);
			}
			else{
				ans=min(res[id]-front-1,back-res[id]);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
