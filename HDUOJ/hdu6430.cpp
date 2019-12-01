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
#define FIN freopen("std.in","r",stdin)
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

struct node{
    int to;
    int next;
}e[maxn];

int head[maxn];
int cnt;
int n,v[maxn];
int ans[maxn];
vector<int> res[maxn];
vector<int> pre[maxn];

void Init_e(){
    cnt=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            res[j].push_back(i);
        }
    }
}

void add(int u,int v){
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void handle(int fa,int son){
    int i=0,j=0;
    vector<int> f;
    while(i<(int)pre[fa].size()&&j<(int)pre[son].size()){
        if(pre[fa][i]<pre[son][j]){
            f.push_back(pre[fa][i]);
            i++;
        }
        else if(pre[fa][i]>pre[son][j]){
            f.push_back(pre[son][j]);
            j++;
        }
        else{
            ans[fa]=max(ans[fa],pre[fa][i]);
            f.push_back(pre[fa][i]);
            i++;
        }
    }
    while(i<(int)pre[fa].size()){
        f.push_back(pre[fa][i]);
        i++;
    }
    while(j<(int)pre[son].size()){
        f.push_back(pre[son][j]);
        j++;
    }
    pre[fa]=f;
}

void dfs(int u,int fa){
    ans[u]=-1;
    int v;
    for(int i=head[u];i!=-1;i=e[i].next){
        v=e[i].to;
        if(v==fa)
            continue;
        dfs(v,u);
        handle(u,v);
    }
}

int main(void){
    FC;
    FIN;
    Init_e();
    int u;
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>u;
        add(u,i);
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
        pre[i]=res[v[i]];
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<'\n';
    }
	return 0;
}
