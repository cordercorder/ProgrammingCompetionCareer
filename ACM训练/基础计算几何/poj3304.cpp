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

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

/*head------[@cordercorder]*/

namespace mygeo{
    const double eps=1e-8;
    
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
        //计算点积 
        double dot(const Point &a)const{
            return x*a.x+y*a.y;
        }
        //计算叉积 
        double cross(const Point &a)const{
            return x*a.y-y*a.x;
        }
        //计算两点间距离
        double dis(const Point &a)const{
            double ans=(x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);
            return sqrt(ans);
        } 
        //逆时针旋转angle
        Point rotate(double angle){
            return Point(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
        }
        //逆时针旋转90度 
        Point ratate90(){
            return Point(-y,x);
        }
    };
    
    //计算p0p1叉乘p0p2 
    double dbcross(const Point &p0,const Point &p1,const Point &p2){
        return (p1-p0).cross(p2-p0); 
    }
    
    struct Line{
        Point st;
        Point ed;
        Line(){}
        Line(const Point &_st,const Point &_ed):st(_st),ed(_ed){}
        
        //计算线段的长度 
        double Len(){
            return st.dis(ed);
        }
        
        //判断线段a是否在此线段的两侧 
        bool IsBothSide(const Line &a)const{
            if(sign(dbcross(a.st,st,ed))*sign(dbcross(a.ed,st,ed))<=0){
                return true;
            }
            return false;
        }
    };
}

const int maxn=110;

int T;
int n;
mygeo::Line line[maxn];

bool check(mygeo::Point st,mygeo::Point ed){
    mygeo::Line L(st,ed);
    if(mygeo::sign(L.Len())==0){
        return false;
    }
    for(int i=1;i<=n;i++){
        if(!L.IsBothSide(line[i]))
            return false;
    }
    return true;
}

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(check(line[i].st,line[j].st)||check(line[i].st,line[j].ed)||check(line[i].ed,line[j].st)||check(line[i].ed,line[j].ed)){
                puts("Yes!");
                return ;
            }
        }
    }
    puts("No!");
}

int main(void){
    mygeo::Point st,ed;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lf %lf %lf %lf",&st.x,&st.y,&ed.x,&ed.y);
            line[i]=mygeo::Line(st,ed);
        }
        if(n==1){
            puts("Yes!");
        }
        else{
            solve();
        }
    }
    return 0;
}
