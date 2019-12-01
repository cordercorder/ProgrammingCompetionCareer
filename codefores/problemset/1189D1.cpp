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

const int maxn=(int)1e5+10;

vector<int> e[maxn];
int deg[maxn];
int n;
int u,v;

void solve(){
    for(int i=1;i<=n;i++){
        if(deg[i]!=1&&deg[i]<3){
            puts("NO");
            return ;
        }
    }
    puts("YES");
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if(n==2){
        puts("YES");
    }
    else{
        solve();
    }
    return 0;
}
