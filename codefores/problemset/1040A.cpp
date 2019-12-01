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

const int maxn=30;

int n,a,b;
int c[maxn];

void solve(){
	int i=1,j=n;
	int ans=0;
	while(i<=j){
		if((c[i]==0&&c[j]==2)||(c[i]==2&&c[j]==0)){
			ans+=a;
		}
		else if((c[i]==1&&c[j]==2)||(c[i]==2&&c[j]==1)){
			ans+=b;
		}
		else if(c[i]==2&&c[j]==2){
			if(i!=j)
				ans+=2*min(a,b);
			else
				ans+=min(a,b);
		}
		else if((c[i]==0&&c[j]==1)||(c[i]==1&&c[j]==0)){
			cout<<"-1";
			return ;
		}
		i++;
		j--;
	}
	cout<<ans;
}

int main(void){
	FC;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	solve();
	return 0;
}
