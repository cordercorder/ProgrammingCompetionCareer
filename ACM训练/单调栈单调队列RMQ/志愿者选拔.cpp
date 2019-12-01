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

const int maxn=1e6+10;

ll q[maxn],a[maxn];
ll t;
ll front,back;

int main(void){
	char s[100],tmp[100];
	ll v;
	scanf("%lld",&t);
	ll cnt,tot;
	while(t--){
		front=back=0;
		cnt=0;
		tot=1;
		scanf("%s",s+1);
		while(1){
			scanf("%s",s+1);
			if(s[1]=='C'){
				scanf("%s %lld",tmp+1,&v);
				a[++cnt]=v;
				while(front<back&&a[q[back]]<a[cnt]){
					--back;
				}
				q[++back]=cnt;
			}
			else if(s[1]=='G'){
				while(front<back&&q[front+1]<=tot){
					++front;
				}
				++tot;
			}
			else if(s[1]=='Q'){
				if(tot>cnt){
					puts("-1");
					continue;
				}
				printf("%lld\n",a[q[front+1]]);
			}
			else if(s[1]=='E'){
				break;
			}		
		}
	}
	return 0;
}
