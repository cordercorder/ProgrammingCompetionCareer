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

const int maxn=1e4+10;

int n,m;
vector<int> e[maxn];
int cnt,tot;
int dfn[maxn],low[maxn];
bool isv[maxn];
stack<int> sta;
int belong[maxn];
int out[maxn];
int num[maxn];

void Tarjan(int u){
    low[u]=dfn[u]=++cnt;
    isv[u]=true;
    sta.push(u);
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!dfn[v]){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(isv[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        ++tot;
        while(1){
            v=sta.top();
            sta.pop();
            isv[v]=false;
            belong[v]=tot;
            num[tot]++;
            if(v==u)
                break;
        }
    }
}

void solve(){
    tot=cnt=0;
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            Tarjan(i);
        }
    }
    int v;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)e[i].size();j++){
            v=e[i][j];
            if(belong[v]!=belong[i]){
                out[belong[i]]++;
            }
        }
    }
    int ans=1,sum=0;
    for(int i=1;i<=tot;i++){
        if(out[i]==0){
            sum++;
            ans=i;
        }
    }
    if(sum>1){
        puts("0");
        return ;
    }
    printf("%d\n",num[ans]);
}

int main(void){
    int u,v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
    }
    solve();
	return 0;
}
