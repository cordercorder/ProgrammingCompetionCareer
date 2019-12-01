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
using pii=pair<int,int>; 

/*head------[@cordercorder]*/

const int maxn=(int)1e3+10;

char s[maxn][maxn];
int n,m,p;
int sp[11];

struct node{
    int x;
    int y;
    int steps;
    node():steps(0){}
    node(int _x,int _y,int _steps):x(_x),y(_y),steps(_steps){}
};
bool isv[maxn][maxn];
vector<node> st[11]; 
int ans[11];
queue<node> q[11],q_tmp[11];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void bfs(int id,node &st){
    queue<node> qq;
    qq.push(st);
    node now,tmp;
    while(!qq.empty()){
        now=qq.front();
        qq.pop();
        for(int i=0;i<4;i++){
            tmp.x=now.x+dx[i];
            tmp.y=now.y+dy[i];
            if(tmp.x>=1&&tmp.x<=n&&tmp.y>=1&&tmp.y<=m&&s[tmp.x][tmp.y]=='.'&&!isv[tmp.x][tmp.y]){
                tmp.steps=now.steps+1;
                if(tmp.steps<=sp[id]){
                    isv[tmp.x][tmp.y]=true;
                    ans[id]++;
                    qq.push(tmp);
                    q_tmp[id].push(node(tmp.x,tmp.y,0));
                }
            }
        }
    }
}

void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<(int)isv[i][j];
        }
        cout<<endl;
    }
}

void solve(){
    for(int i=1;i<=p;i++){
        for(int j=0;j<(int)st[i].size();j++){
            q[i].push(st[i][j]);
        }
        ans[i]+=(int)st[i].size();
    }
    node now,tmp;
    int sum;
    while(true){
        for(int i=1;i<=p;i++){
            while(!q[i].empty()){
                now=q[i].front();
                q[i].pop();
                isv[now.x][now.y]=true;
                bfs(i,now);
            }
            q[i]=q_tmp[i];
//            deb((int)q_tmp[i].size());
            while(!q_tmp[i].empty()){
                q_tmp[i].pop();
            }
//            print();
//            cout<<endl;
        }
        sum=0;
        for(int i=1;i<=p;i++){
            if(q[i].empty()){
                sum++;
            }
        }
        if(sum==p)
            break;
    }
    for(int i=1;i<=p;i++){
        cout<<ans[i]<<" ";
    }
}

int main(void){
    FC;
    cin>>n>>m>>p;
    node tmp;
    for(int i=1;i<=p;i++){
        cin>>sp[i];
    }
    for(int i=1;i<=n;i++){
        cin>>(s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]<='9'&&s[i][j]>='1'){
                tmp.x=i;
                tmp.y=j;
                st[(int)(s[i][j]-'0')].push_back(tmp);
            }
        }
    }
    solve();
    return 0;
}
