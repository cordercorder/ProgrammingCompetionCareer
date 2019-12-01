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
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
/*head------[@cordercorder]*/

namespace mygeo{
    typedef double db;
    
    const db eps=1e-10;
    
    int sign(db k){
        if(k>eps){
            return 1;
        }
        else if(k<-eps){
            return -1;
        }
        return 0;
    }
    
    struct Point{
        db x;
        db y;
        Point(){}
        Point(db _x,db _y):x(_x),y(_y){}
        Point operator+(const Point &a)const{
            return Point(x+a.x,y+a.y);
        }
        Point operator-(const Point &a)const{
            return Point(x-a.x,y-a.y);
        }
        Point operator*(db k){
            return Point(x*k,y*k);
        }
        Point operator/(db k){
            return Point(x/k,y/k);
        }
        //计算点积
        db dot(const Point &a)const{
            return x*a.x+y*a.y;
        }
        //计算叉积
        db cross(const Point &a)const{
            return x*a.y-y*a.x;
        }
        //计算两点间距离
        db dis(const Point &a)const{
            db ans=(x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);
            return sqrt(ans);
        } 
        //逆时针旋转angle
        Point rotate(db angle){
            return Point(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
        }
        //逆时针旋转90度 
        Point ratate90(){
            return Point(-y,x);
        }
    };
    
    //计算p0p1叉乘p0p2,可以用于判断三点共线 
    db dbcross(const Point &p0,const Point &p1,const Point &p2){
        return (p1-p0).cross(p2-p0); 
    }
    
    //可以看成起点到终点的一个向量 
    struct Line{
        Point st;//起点 
        Point ed;//终点 
        db angle;//角度 [-180, 180]
        Line(){}
        Line(const Point &_st,const Point &_ed):st(_st),ed(_ed){}
        
        void get_angle(){
            angle=atan2(ed.y-st.y,ed.x-st.x);
        }
        
        //判断点a是否在向量的左边,1(a在直线左边),-1(a在直线右边),0(a与直线共线) 
        int toLeftTest(const Point &a)const{
            int x=sign((ed-st).cross(a-st));
            if(x>0){
                return 1;
            }
            else if(x<0){
                return -1;
            }
            return 0;
        }
        
        //极角排序，排序的结果为3,4,1,2象限 
        bool operator<(const Line &a)const{
            int x=sign(angle-a.angle);
            if(x==0){
                return a.toLeftTest(st)==1;
            }
            return x<0;
        }
        
        //计算线段的长度 
        db Len()const{
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
                        db maxL=max(st.dis(a.st),st.dis(a.ed));
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
        
        //又是一个求两直线交点的函数,用于支持半平面空间交函数 
        Point crosspoint(const Line &a)const{
            db a1=(a.ed-a.st).cross(st-a.st);
            db a2=(a.ed-a.st).cross(ed-a.st);
            db x=(st.x*a2-ed.x*a1)/(a2-a1);
            db y=(st.y*a2-ed.y*a1)/(a2-a1);
            if(sign(x)==0){
                x=0;
            }
            if(sign(y)==0){
                y=0;
            }
            return Point(x,y);
        }
    };
    
    //求直线集合l的半平面空间交,集合l中的直线应该逆时针给出,还需要q和ip两个和l大小相似的数组作为参数 
    //注意使用get_angle函数 
    bool half_plane(Line *l,Line *q,Point *ip,int N){
        sort(l+1,l+1+N);//极角排序 
        int tot=1;
        for(int i=2;i<=N;i++){
            if(sign(l[i].angle-l[tot].angle)==1){
                l[++tot]=l[i];
            }
        }
        N=tot;
        int head=1,tail=2;
        q[1]=l[1];
        q[2]=l[2];
        for(int i=3;i<=N;i++){
            while(head<tail&&l[i].toLeftTest(q[tail].crosspoint(q[tail-1]))==-1){
                tail--;
            }
            while(head<tail&&l[i].toLeftTest(q[head].crosspoint(q[head+1]))==-1){
                head++;
            }
            q[++tail]=l[i];
        }
        
        while(head<tail&&q[head].toLeftTest(q[tail].crosspoint(q[tail-1]))==-1){
            tail--;
        }
        while(head<tail&&l[tail].toLeftTest(q[head].crosspoint(q[head+1]))==-1){
            head++;
        }
        
        if(tail-head+1<=2){
            return false;
        }
        return true;
    }
}

const int maxn=110;

int N;
mygeo::Point p[maxn],ip[maxn];
mygeo::Line l[maxn],q[maxn];

int main(void){
    for(int _=1;;_++){
        scanf("%d",&N);
        if(N==0)
            break;
        for(int i=1;i<=N;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        int cnt=0;
        for(int i=N;i>=2;i--){
            l[++cnt]=mygeo::Line(p[i],p[i-1]);
            l[cnt].get_angle();
        }
        l[++cnt]=mygeo::Line(p[1],p[N]);
        l[cnt].get_angle();
        printf("Floor #%d\n",_);
        if(!mygeo::half_plane(l,q,ip,N)){
            puts("Surveillance is impossible.");
        }
        else{
            puts("Surveillance is possible.");
        }
        puts("");
    }
    return 0;
}
