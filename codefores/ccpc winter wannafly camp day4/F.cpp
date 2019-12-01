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

const int maxn=8;

struct node{
    int x;
    int y;
};
bool isv[maxn][maxn];
int n,m;
int stx,sty;
int edx,edy;
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};

bool check(){
    queue<node> q;
    q.push({stx,sty});
    node now,tmp;
    while(!q.empty()){
        now=q.front();
        if(now.x==edx&&now.y==edy)
            return true;
        q.pop();
        for(int i=0;i<8;i++){
            tmp.x=now.x+dx[i];
            tmp.y=now.y+dy[i];
            if(tmp.x>=1&&tmp.x<=n&&tmp.y>=1&&tmp.y<=m&&!isv[tmp.x][tmp.y]){
                isv[tmp.x][tmp.y]=true;
                q.push(tmp);
            }
        }
    }
    return false;
}

void solve(){
    bool f1,f2;
    if((stx%2==1&&sty%2==1)||(stx%2==0&&sty%2==0)){
        f1=true;
    }
    else{
        f1=false;
    }
    if((edx%2==1&&edy%2==1)||(edx%2==0&&edy%2==0)){
        f2=true;
    }
    else{
        f2=false;
    }
    if(f1==f2){
        cout<<"No"<<'\n';
    }
    else{
        cout<<"Yes"<<'\n';
    }
}

int main(void){
    FC;
    cin>>n>>m;
    cin>>stx>>sty;
    cin>>edx>>edy;
    if(n<=6&&m<=6&&check()==false){
        cout<<"No"<<'\n';
    }
    else{
        solve();
    }
    return 0;
}
