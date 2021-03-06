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

int n,m;
vector<int> res;
int tmp[20];

bool check(int x){
	int cnt=0;
	while(x){
		tmp[++cnt]=x%10;
		x/=10;
	}
	for(int i=1;i<cnt;i++){
		if(tmp[i]==2&&tmp[i+1]==6){
			return 0;
		}
	}
	return 1;
}

void solve(int pos,int num){
	if(pos>8||num>1000000)
		return ;
	if(check(num)){
		res.push_back(num);
	}
	for(int i=0;i<=9;i++){
		if(i==4)
			continue;
		solve(pos+1,num*10+i);
	}
}

int main(void){
	for(int i=1;i<=9;i++){
		if(i==4)
			continue;
		solve(2,i);
	}
	sort(res.begin(),res.end());
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0&&m==0)
			break;
		printf("%d\n",upper_bound(res.begin(),res.end(),m)-lower_bound(res.begin(),res.end(),n));
	}
	return 0;
}
