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

const int maxn=50+10;

int x[maxn],y[maxn];
int n;
int s1,s2;

int main(void){
	scanf("%d",&n);
	s1=0;
	s2=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		s1+=x[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&y[i]);
		s2+=y[i];
	}
	if(s1>=s2){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}
