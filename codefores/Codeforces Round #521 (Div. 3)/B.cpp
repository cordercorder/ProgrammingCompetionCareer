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
#include<list>

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

int n;
int a[maxn];

void solve(){
    int ans=0;
    for(int i=2;i<n;i++){
        if(a[i-1]==1&&a[i+1]==1&&a[i]==0){
            a[i+1]=0;
            ans++;
        }
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    solve();
	return 0;
}
