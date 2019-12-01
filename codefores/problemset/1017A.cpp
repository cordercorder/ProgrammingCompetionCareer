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

const int maxn=1e3+10;

struct node{
	int a;
	int b;
	int c;
	int d;
	int sum;
	int id;
}res[maxn];
int n;

bool cmp(const node &a,const node &b){
	if(a.sum>b.sum)
		return 1;
	if(a.sum==b.sum&&a.id<b.id)
		return 1;
	return 0;
}

int main(void){
	FC;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i].a>>res[i].b>>res[i].c>>res[i].d;
		res[i].sum=res[i].a+res[i].b+res[i].c+res[i].d;
		res[i].id=i;
	}
	sort(res+1,res+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(res[i].id==1){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
