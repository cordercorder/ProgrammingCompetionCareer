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
int T;
int n,m;
vector<bool> res[maxn];
struct node{
    int x;
    int y;
    int steps;
    node():steps(0){}
    void operator=(const node &a){
        this->x=a.x;
        this->y=a.y;
        this->steps=a.steps;
    }
};
node st,ed;
vector<bool> isv[maxn][2];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int front,back;

void go1(node &tmp,const node &now,queue<node>&que){
    for(int i=2;i<4;i++){
        int nx=now.x+dx[i];
        int ny=now.y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&isv[nx][(now.steps+1)%2][ny]==false){
            tmp.x=nx;
            tmp.y=ny;
            tmp.steps=now.steps+1;
            que.push(tmp);
            isv[nx][(now.steps+1)%2][ny]=true;
        }
    }
}

void go0(node &tmp,const node &now,queue<node>&que){
    for(int i=0;i<2;i++){
        int nx=now.x+dx[i];
        int ny=now.y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&isv[nx][(now.steps+1)%2][ny]==false){
            tmp.x=nx;
            tmp.y=ny;
            tmp.steps=now.steps+1;
            que.push(tmp);
            isv[nx][(now.steps+1)%2][ny]=true;
        }
    }
}

void solve(){
    queue<node> que;
    isv[st.x][0][st.y]=true;
    que.push(st);
    node now,tmp;
    int nx,ny;
    while(!que.empty()){
        now=que.front();
        que.pop();
        if(now.x==ed.x&&now.y==ed.y){
            printf("%d\n",now.steps);
            return ;
        }
        if(now.steps&1){
            if(res[now.x][now.y]==true){
                go0(tmp,now,que);
            }
            else{
                go1(tmp,now,que);
            }
        }
        else{
            if(res[now.x][now.y]==true){
                go1(tmp,now,que);
            }
            else{
                go0(tmp,now,que);
            }
        }
    }
    puts("-1");
}

int main(void){
    scanf("%d",&T);
    int tmp;
    while(T--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            res[i].resize(m+1);
            isv[i][0].assign(m+1,false);
            isv[i][1].assign(m+1,false);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&tmp);
                if(tmp==1){
                    res[i][j]=true;
                }
                else{
                    res[i][j]=false;
                }
            }
        }
        scanf("%d %d %d %d",&st.x,&st.y,&ed.x,&ed.y);
        solve();
        for(int i=1;i<=n;i++){
            res[i].clear();
            isv[i][0].clear();
            isv[i][1].clear();
        }
    }
	return 0;
}
