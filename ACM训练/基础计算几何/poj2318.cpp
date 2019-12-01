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
#include<list>
#include<set>
#include<map>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<#x<<"------>"<<x<<endl 

const double PI=acos(-1.0);  
const double eps=1e-8;
const long long maxw=(long long)1e17+(long long)10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

/*head------[@cordercorder]*/

const int maxn=5010;

int sign(double k){
    if(k>eps){
        return 1;
    }
    else if(k<-eps){
        return -1;
    }
    return 0;
}

struct Point{
    double x;
    double y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
    void Set(double _x,double _y){
        x=_x;
        y=_y;
    }
    Point operator+(const Point &a)const{
        return Point(x+a.x,y+a.y);
    }
    Point operator-(const Point &a)const{
        return Point(x-a.x,y-a.y);
    }
    Point operator*(double k){
        return Point(x*k,y*k);
    }
    Point operator/(double k){
        return Point(x/k,y/k);
    }
    double dot(const Point &a)const{
        return x*a.x+y*a.y;
    }
    double cross(const Point &a)const{
        return x*a.y-y*a.x;
    }
    //逆时针旋转angle度
    Point rotate(double angle){
        return Point(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
    }
    //逆时针旋转90度 
    Point ratate90(){
        return Point(-y,x);
    }
};

int n,m;
double x[3],y[3];
Point toy[maxn];
double U[maxn],L[maxn];
int cnt[maxn];

bool check(int x,int pos){
    Point par(U[x]-L[x],y[1]-y[2]);
    Point p(toy[pos].x-L[x],toy[pos].y-y[2]);
    if(sign(par.cross(p))>0){
        return true;
    }
    return false;
}

void solve(){
    int l,r,mid;
    for(int i=1;i<=m;i++){
        l=1;
        r=n+1;
        while(l<r){
            mid=(l+r)>>1;
            if(check(mid,i)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        if(l==n+1){
            cnt[n]++;
        }
        else if(check(l,i)){
            cnt[l-1]++;
        }
    }
    for(int i=0;i<=n;i++){
        printf("%d: %d\n",i,cnt[i]);
        cnt[i]=0;
    }
}

int main(void){
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        scanf("%d %lf %lf %lf %lf",&m,&x[1],&y[1],&x[2],&y[2]);
        for(int i=1;i<=n;i++){
            scanf("%lf %lf",&U[i],&L[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%lf %lf",&toy[i].x,&toy[i].y);
        }
        solve();
        puts("");
    }
    return 0;
}
