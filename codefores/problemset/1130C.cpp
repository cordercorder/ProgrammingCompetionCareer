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

const int maxn=55;

pii st,ed;
int n;
char s[maxn][maxn];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool isv[maxn][maxn];
vector<pii> ret[2];

bool dfs(pii now,int id){
    isv[now.first][now.second]=true;
    ret[id].push_back(now);
    if(now==ed&&id==0)
        return true;
    pii tmp;
    for(int i=0;i<4;i++){
        tmp.first=now.first+dx[i];
        tmp.second=now.second+dy[i];
        if(tmp.first>=1&&tmp.first<=n&&tmp.second>=1&&tmp.second<=n&&s[tmp.first][tmp.second]=='0'&&!isv[tmp.first][tmp.second]){
            if(dfs(tmp,id))
                return true;
        }
    }
    return false;
}

void solve(){
    if(dfs(st,0)){
        puts("0");
        return ;
    }
    dfs(ed,1);
    int ans=(int)1e9+10;
    for(pii u:ret[0]){
        for(pii v:ret[1]){
            ans=min(ans,(u.first-v.first)*(u.first-v.first)+(u.second-v.second)*(u.second-v.second));
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&n);
    scanf("%d %d",&st.first,&st.second);
    scanf("%d %d",&ed.first,&ed.second);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    solve();
    return 0;
}
