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

const int maxn=1e3+10; 

int a[maxn];
int n;


void solve(){
    int ans=0;
    bool f;
    for(int i=1;i<=n;){
        int j=i;
        f=false;
        while(j<n&&a[j]+1==a[j+1]){
            j++;
            f=true;
        }
        if(a[i]==1||a[j]==1000){
            ans=max(ans,j-i);
        }
        else{
            ans=max(ans,j-i-1);
        }
        if(f){
            i=j;
        }
        else{
            i=j+1;
        }
    }
    cout<<ans<<endl;
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
