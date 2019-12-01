#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e3+10;

string s,t;
int n,m,q;
int num[maxn];
int sum[maxn];

void handle(){
	string tmp;
	sum[0]=0;
	for(int i=0;i<(n-m+1);i++){
		tmp=s.substr(i,m);
		if(tmp==t){
			num[i+1]=1;
		}		
		sum[i+1]=sum[i]+num[i+1];
	}
}

int main(void){
	int l,r;
	scanf("%d %d %d",&n,&m,&q);
	cin>>s>>t;
	handle();
	while(q--){
		scanf("%d %d",&l,&r);
		r=r-m+1;
		//deb(r);
		if(r<(l-1)){
			puts("0");
			continue;
		}
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}
