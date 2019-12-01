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

const int maxn=(int)2e5+10; 

char s[maxn];
int n;
int x,y;
int dx[maxn],dy[maxn];

bool check(int ret){
    int len,l,nx,ny;
    for(int r=ret;r<=n;r++){
        l=r-ret+1;
        nx=dx[l-1]+dx[n]-dx[r];
        ny=dy[l-1]+dy[n]-dy[r];
        len=abs(nx-x)+abs(ny-y);
        if(len<=ret&&(ret-len)%2==0)
            return true;
    }
    return false;
}

void solve(){
    for(int i=1;i<=n;i++){
        if(s[i]=='U'){
            dx[i]=dx[i-1];
            dy[i]=dy[i-1]+1;
        }
        else if(s[i]=='D'){
            dx[i]=dx[i-1];
            dy[i]=dy[i-1]-1;
        }
        else if(s[i]=='L'){
            dx[i]=dx[i-1]-1;
            dy[i]=dy[i-1];
        }
        else{
            dx[i]=dx[i-1]+1;
            dy[i]=dy[i-1]; 
        }
    }
    int l=0,r=n+1,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(l==n+1){
        puts("-1");
    }
    else{
        printf("%d\n",l);
    }
}

int main(void){
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%d %d",&x,&y);
    solve();
    return 0;
}
