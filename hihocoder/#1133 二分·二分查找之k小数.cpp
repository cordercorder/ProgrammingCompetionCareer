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
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e6+10;

int a[maxn];
int n,k;

int main(void){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
	    scanf("%d",&a[i]);
    }
    if(k>n){
        puts("-1");
        return 0;
    }
	nth_element(a+1,a+k,a+1+n);
	printf("%d\n",a[k]);
	return 0;
}
