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

const int maxn=1e2+10;

int T;
int n,m,A,B;
int a[maxn][maxn];

void solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]<A||a[i][j]>B)
                ans++;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d",&n,&m,&A,&B);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        if(A>B){
            puts("No Solution");
            continue;
        }
        solve();
    }
	return 0;
}
