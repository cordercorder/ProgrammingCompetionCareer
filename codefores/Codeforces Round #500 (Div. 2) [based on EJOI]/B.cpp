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

const int maxn=1e5+10;

int a[maxn];
int n,x;
map<int,int> mp1,mp2;
map<int,int>::iterator it;
pii res[maxn];

bool cmp(const pii &a,const pii &b){
	return a.first<b.first;
}

void solve(){
	for(it=mp1.begin();it!=mp1.end();it++){
		if(it->second>=2){
			puts("0");
			return ;
		}
	}
	for(int i=1;i<=n;i++){
		res[i].first=a[i];
		res[i].second=i;
	}
	sort(res+1,res+1+n);
	int tmp,pos;
	for(int i=1;i<=n;i++){
		tmp=a[i]&x;
		pos=lower_bound(res+1,res+1+n,pii(tmp,n+1),cmp)-res;
		if(pos!=(n+1)&&res[pos].first==tmp&&res[pos].second!=i){
			puts("1");
			return ;
		}
	}
	for(it=mp2.begin();it!=mp2.end();it++){
		if(it->second>=2){
			puts("2");
			return ;
		}
	}
	puts("-1");
}

int main(void){
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mp1[a[i]]++;
		mp2[a[i]&x]++;
	}
	solve();
	return 0;
}
