#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    for(auto i:a){
        cerr<<i<<" ";
    }
    cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}
void err(int a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,string>; 

/*head------[@cordercorder]*/

const int maxn=3e5+10;

int n,m;
char s[maxn];
vector<int> e[maxn];
int in[maxn];
vector<int> ret;
bool isv[maxn];
int tot[maxn][30];
int ans;

bool check(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
            ret.push_back(i);
        }
    }
    int now,u;
    int cnt=0;
    while(!q.empty()){
        now=q.front();
        q.pop();
        cnt++;
        for(int i=0;i<(int)e[now].size();i++){
            u=e[now][i];
            in[u]--;
            if(in[u]==0){
                q.push(u);
            }
        }
    }
    return cnt==n;
}

void dfs(int u){
    isv[u]=true;
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!isv[v]){
            dfs(v);
        }
    }
    vector<int> maxcnt(26,0);
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        for(int j=0;j<26;j++){
            maxcnt[j]=max(maxcnt[j],tot[v][j]);
        }
    }
    tot[u][(int)(s[u]-'a')]=1;
    for(int i=0;i<26;i++){
        tot[u][i]+=maxcnt[i];
        ans=max(ans,tot[u][i]);
    }
}

void solve(){
    int u;
    for(int i=0;i<(int)ret.size();i++){
        u=ret[i];
        dfs(u);
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    int u,v;
    cin>>n>>m;
    cin>>(s+1);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        e[u].push_back(v);
        in[v]++;
    }
    if(!check()){
        cout<<"-1"<<'\n';
        return 0;
    }
    solve();
    return 0;
}
