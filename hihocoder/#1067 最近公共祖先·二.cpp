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

const int maxn=1e5+10;

map<string,int> isv;
int cnt;
int n,m;
string fa,son;
vector<int> e[maxn];
string q1[maxn],q2[maxn],num[maxn];
int f[maxn];
vector<int> ans;
vector<pii> q[maxn];

int handle(const string &s){
    if(isv.count(s)==0){
        isv[s]=++cnt;
        num[cnt]=s;
        return cnt;
    }
    return isv[s];
}

int Find(int x){
    return f[x]==x?x:f[x]=Find(f[x]);
}

void solve(int u,int fa){
    f[u]=u;
    int v,id;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v==fa)
            continue;
        solve(v,u);
    }
    for(int i=0;i<(int)q[u].size();i++){
        v=q[u][i].second;
        id=q[u][i].first;
        if(f[v]==-1)
            continue;
        if(ans[id]!=-1)
            continue;
        ans[id]=Find(v);
    }
    if(fa!=0)
        f[u]=Find(fa);
}

int main(void){
	FC;
	cin>>n;
	cnt=0;
	int u,v;
	for(int i=0;i<n;i++){
	    cin>>fa>>son;
	    u=handle(fa);
	    v=handle(son);
	    e[u].push_back(v);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>q1[i]>>q2[i];
        u=handle(q1[i]);
        v=handle(q2[i]);
        q[u].push_back(pii(i,v));
        q[v].push_back(pii(i,u));
    }
    ans.resize(m+1,-1);
    memset(f,-1,sizeof(f));
    solve(1,0);
    for(int i=0;i<m;i++){
        cout<<num[ans[i]]<<'\n';
    }
	return 0;
}
