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

int cnt,head[maxn];
vector<int> res[maxn];
int n,v[maxn];
vector<int> pre[maxn];
int ans[maxn];

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
    vector<int> tmp;
    int num1,num2;
    while(i<(int)pre[fa].size()&&j<(int)pre[son].size()){
        num1=pre[fa][i];
        num2=pre[son][j];
        if(num1<num2){
            tmp.push_back(num1);
            i++;
        }
        else if(num1>num2){
            tmp.push_back(num2);
            j++;
        }
        else{
            tmp.push_back(num1);
            ans[fa]=max(ans[fa],num1);
            i++;
            j++;
        }
    }
    while(i<(int)pre[fa].size()){
        tmp.push_back(pre[fa][i]);
        i++;
    }
    while(j<(int)pre[son].size()){
        tmp.push_back(pre[son][j]);
        j++;
    }
    pre[fa]=tmp;
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
    //FIN;
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
