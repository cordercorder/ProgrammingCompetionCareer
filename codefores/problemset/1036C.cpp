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

ll t;
ll L,R;
vector<ll> res;

void solve(ll pos,ll sum,ll num){
	if(pos>20)
		return ;
	res.push_back(num);
	for(ll i=0;i<=9;i++){
		if(i==0){
			solve(pos+1,sum,num*10);
		}
		if(sum<3&&i!=0){
			solve(pos+1,sum+1,num*10+i);
		}
		if(sum==3&&i!=0)
			break;
	}
}

int main(void){
	FC;
	for(int i=1;i<=9;i++){
		solve(2,1,i);
	}
	sort(res.begin(),res.end());
	cin>>t;
	while(t--){
		cin>>L>>R;
		cout<<upper_bound(res.begin(),res.end(),R)-lower_bound(res.begin(),res.end(),L)<<'\n';
	}
	return 0;
}
