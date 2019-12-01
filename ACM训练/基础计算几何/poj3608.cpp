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

const long double PI=acos(-1.0);  
const double eps=1e-9;

/*head------[@cordercorder]*/


const int maxn=(int)1e4+10;

struct Point{
    double x;
    double y;
    
    Point(double _x=0,double _y=0):x(_x),y(_y){}
    
    double Len(){
        return sqrt(x*x+y*y);
    }
    
    Point operator-(const Point &a)const{
        return Point(x-a.x,y-a.y);
    }
    
    double cross(const Point &a)const{
        return x*a.y-a.x*y;
    }
};

int sign(double x){
    if(x>eps)
        return 1;
    else if(x<-eps)
        return -1;
    return 0;
}

int N,M;
Point p[maxn],q[maxn],piv;

//C到直线AB的距离 
double dis(const Point &A,const Point &B,const Point &C){
    return abs((B-A).cross(C-A))/sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

bool cmp(const Point &a,const Point &b){
    int x=(a-piv).cross(b-piv);
    if(x>0)
        return true;
    else if(x==0){
        return sign((a-piv).Len()<(b-piv).Len())<0;
    }
    return false;
}

void handle(Point *res,int n){
    int id=0;
    for(int i=0;i<n;i++){
        int x=sign(res[i].y-res[id].y);
        if(x<0){
            id=i;
        }
        else if(x==0&&sign(res[i].x-res[id].x)<0){
            id=i;
        }
    }
    swap(res[id],res[0]);
    sort(res+1,res+n,cmp);
    vector<Point> tmp(n);
    tmp[0]=res[0];
    tmp[1]=res[1];
    int tot=1;
    for(int i=2;i<n;i++){
        while(tot>0&&sign((tmp[tot]-tmp[tot-1]).cross(res[i]-tmp[tot-1]))<0){
            tot--;
        }
        tmp[++tot]=res[i];
    }
    for(int i=0;i<n;i++)
        res[i]=tmp[i];
}

double solve(Point *p,Point *q,int N,int M){
    int ymin=0,ymax=0;
    double ans=1e10,t;
    for(int i=0;i<N;i++){
        if(p[i].y<p[ymin].y){
            ymin=i;
        }
    }
    for(int i=0;i<M;i++){
        if(q[i].y>q[ymax].y){
            ymax=i;
        }
    }
    p[N]=p[0];
    q[M]=q[0];
    for(int i=0;i<N;i++){
        while((t=sign((q[ymax+1]-p[ymin+1]).cross(p[ymin]-p[ymin+1])-(q[ymax]-p[ymin+1]).cross(p[ymin]-p[ymin+1])))>0)
            ymax=(ymax+1)%M;
        if(sign(t)==0){
            ans=min(ans,dis(q[ymax],q[ymax+1],p[ymin]));
            ans=min(ans,dis(q[ymax],q[ymax+1],p[ymin+1]));
            ans=min(ans,dis(p[ymin],p[ymin+1],q[ymax]));
            ans=min(ans,dis(p[ymin],p[ymin+1],q[ymax+1]));
        }
        else{
            ans=min(ans,dis(p[ymin],p[ymin+1],q[ymax]));
        }
        ymin=(ymin+1)%N;
    }
    return ans;
}

int main(void){
    while(scanf("%d %d",&N,&M)){
        if(N==0&&M==0)
            break;
        for(int i=0;i<N;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        for(int i=0;i<M;i++){
            scanf("%lf %lf",&q[i].x,&q[i].y);
        }
        printf("%.8lf\n",min(solve(p,q,N,M),solve(q,p,M,N)));
    }
    return 0;
}
