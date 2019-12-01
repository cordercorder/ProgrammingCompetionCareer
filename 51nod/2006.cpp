#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define deb(x) cerr<<#x<<"------>"<<x<<endl

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

typedef long long ll;
typedef unsigned long long ull;

/*head------[@cordercorder]*/

const int maxn=110;

int n,m;
vector<int> e[maxn];
bool isv[maxn];
int link[maxn];

bool dfs(int u){
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!isv[v]){
            isv[v]=true;
            if(link[v]==0||dfs(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}

void solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(isv,false,sizeof(isv));
        if(dfs(i)){
            ans++;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&n,&m);
    int u,v;
    while(true){
        scanf("%d %d",&u,&v);
        if(u==-1&&v==-1){
            break;
        }
        e[u].push_back(v);
    }
    solve();
    return 0;
}
