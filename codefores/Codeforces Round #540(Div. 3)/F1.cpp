#include<bits/stdc++.h>

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

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

/*head------[@cordercorder]*/

const int maxn=(int)3e5+10;

int a[maxn];
vector<int> e[maxn];
int ret[2];
int sum[maxn][2];
int ans,n;

void dfs(int u,int fa){
    if(a[u]==1){
        sum[u][0]=1;
    }
    else if(a[u]==2){
        sum[u][1]=1;
    }
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dfs(v,u);
            sum[u][0]+=sum[v][0];
            sum[u][1]+=sum[v][1];
        }
    }
}

void dfs2(int u,int fa){
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            if((sum[v][0]==ret[0]&&sum[v][1]==0)||(sum[v][1]==ret[1]&&sum[v][0]==0)){
                ans++;
            }
            dfs2(v,u);
        }
    }
}

void solve(){
    dfs(1,0);
    dfs2(1,0);
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1){
            ret[0]++;
        }
        else if(a[i]==2){
            ret[1]++;
        }
    }
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
