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

const int maxn=(int)1e4+10;

int n;
int mine;
pii a[maxn];
bool isv[maxn];

void solve(){
    int cnt,mine2,sum,ans=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(!isv[i]){
            int j=i;
            cnt=0;
            sum=0;
            mine2=(int)1e9;
            while(true){
                sum+=a[j].first;
                mine2=min(mine2,a[j].first);
                isv[j]=true;
                j=a[j].second;
                cnt++;
                if(j==i)
                    break;
            }
            ans+=min(sum+(cnt+1)*mine+mine2,sum+(cnt-2)*mine2);
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&n);
    mine=(int)1e9;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
        mine=min(mine,a[i].first);
    }
    solve();
    return 0;
}
