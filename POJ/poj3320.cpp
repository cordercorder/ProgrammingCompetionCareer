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
#include<list>
#include<set>
#include<map>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

/*head------[@cordercorder]*/

const int maxn=(int)1e6+10;

map<int,int> cnt,res;

int n;
int a[maxn];

void solve(){
    int ans=(int)1e6+10;
    int sum=(int)cnt.size(),tot=0;
    for(int l=1,r=1;l<=n;l++){
        while(r<=n&&tot<sum){
            res[a[r]]++;
            if(res[a[r]]==1){
                tot++;
            }
            r++;
        }
        if(tot==sum){
            ans=min(ans,r-l);
        }
        map<int,int>::iterator it=res.find(a[l]);
        (it->second)--;
        if((it->second)<1){
            tot--;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    solve();
    return 0;
}
