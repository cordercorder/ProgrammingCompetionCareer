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
    const double eps=1e-10;
    
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
    
    //计算p0p1叉乘p0p2,可以用于判断三点共线 
    double dbcross(const Point &p0,const Point &p1,const Point &p2){
        return (p1-p0).cross(p2-p0); 
    }
    
    struct Line{
        Point st;
        Point ed;
        Line(){}
        Line(const Point &_st,const Point &_ed):st(_st),ed(_ed){}
        
        //计算线段的长度 
        double Len()const{
            return st.dis(ed);
        }
        
        //判断线段a是否在此线段的两侧 
        bool IsBothSide(const Line &a)const{
            if(sign(dbcross(a.st,st,ed))*sign(dbcross(a.ed,st,ed))<=0){
                return true;
            }
            return false;
        }
        
        //直线与直线之间的关系  检查与直线a的位置关系(0重合,1平行,2相交)
        int check_pos(const Line &a)const{
            if(sign((ed-st).cross(a.ed-a.st))==0){
                if(sign(dbcross(st,a.st,a.ed))==0){
                    return 0;
                }
                return 1;
            }
            return 2;
        }
        
        //线段与线段之间的关系  检查与线段a的位置关系(0有无数个交点,1四点共线但没有交点,2平行,3相交于端点,4普通相交,5没有交点)
        //有交点(0,3,4),其它情况无交点
        //应该特别注意线段包含的情况,线段包含时应该长的线段在前,短的在后 
        int check_segpos(const Line &a)const{
            if(sign((ed-st).cross(a.ed-a.st))==0){
                if(sign(dbcross(st,a.st,a.ed))==0){
                    int res1=sign((st-a.st).dot(ed-a.st));
                    int res2=sign((st-a.ed).dot(ed-a.ed));
                    if(res1<=0||res2<=0){
                        double maxL=max(st.dis(a.st),st.dis(a.ed));
                        maxL=max(maxL,ed.dis(a.st));
                        maxL=max(maxL,ed.dis(a.ed));
                        if(sign(Len()+a.Len()-maxL)==0){
                            return 3;
                        }
                        return 0;
                    }
                    return 1;
                }
                return 2;
            }
            else{
                int res1=sign(dbcross(a.st,st,ed))*sign(dbcross(a.ed,st,ed));
                int res2=sign(dbcross(st,a.st,a.ed))*sign(dbcross(ed,a.st,a.ed));
                if(res1<=0&&res2<=0){
                    if(res1==0||res2==0){
                        return 3;
                    }
                    else{
                        return 4;
                    }
                }
                return 5;
            }
        }
        
        //判断线段之间的关系(简化版)
        //0有交点(交点个数不确定,可能相交于端点),1四点共线但没有交点,2两线段平行, 3有一个交点,4没有交点
        //0,3有交点,其它情况无交点 
        int check_segpos_sim(const Line &a)const{
            if(sign((ed-st).cross(a.ed-a.st))==0){
                if(sign(dbcross(st,a.st,a.ed))==0){
                    int res1=sign((st-a.st).dot(ed-a.st));
                    int res2=sign((st-a.ed).dot(ed-a.ed));
                    if(res1<=0||res2<=0){
                        return 0;
                    }
                    return 1;
                }
                return 2;
            }
            else{
                int res1=sign(dbcross(a.st,st,ed))*sign(dbcross(a.ed,st,ed));
                int res2=sign(dbcross(st,a.st,a.ed))*sign(dbcross(ed,a.st,a.ed));
                if(res1<=0&&res2<=0){
                    return 3;
                }
                return 4;
            }
        }
        
        //计算与直线a的交点(可用于求两线段的交点，但必须先判断两线段有交点) 
        Point intersection(const Line &a)const{
            Point p1=st;
            Point p2=ed;
            Point q1=a.st;
            Point q2=a.ed;
            return p1+(p2-p1)*((q2-q1).cross(q1-p1)/(q2-q1).cross(p2-p1));
        }
    };
}

const int maxn=35;

int n;
mygeo::Line line[maxn];
vector<mygeo::Point> p;
mygeo::Point ret;

void solve(){
    int tmp,ans=(int)1e9,cnt;
    mygeo::Line L;
    for(int i=0;i<(int)p.size();i++){
        cnt=0;
        L=mygeo::Line(p[i],ret);
        for(int j=1;j<=n;j++){
            tmp=L.check_segpos_sim(line[j]);
            if(tmp==0||tmp==3){
                cnt++; 
            }
        }
        ans=min(ans,cnt);
    }
    printf("Number of doors = %d\n",ans);
}

int main(void){
    mygeo::Point st,ed;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf %lf %lf",&st.x,&st.y,&ed.x,&ed.y);
        line[i]=mygeo::Line(st,ed);
        p.push_back(st);
        p.push_back(ed);
    }
    scanf("%lf %lf",&ret.x,&ret.y);
    if(n==0){
        printf("Number of doors = 1\n");
    }
    else{
        solve();
    }
    return 0;
}
