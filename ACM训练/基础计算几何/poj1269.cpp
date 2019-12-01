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
        //������ 
        double dot(const Point &a)const{
            return x*a.x+y*a.y;
        }
        //������ 
        double cross(const Point &a)const{
            return x*a.y-y*a.x;
        }
        //������������
        double dis(const Point &a)const{
            double ans=(x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);
            return sqrt(ans);
        } 
        //��ʱ����תangle
        Point rotate(double angle){
            return Point(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
        }
        //��ʱ����ת90�� 
        Point ratate90(){
            return Point(-y,x);
        }
    };
    
    //����p0p1���p0p2,���������ж����㹲�� 
    double dbcross(const Point &p0,const Point &p1,const Point &p2){
        return (p1-p0).cross(p2-p0); 
    }
    
    struct Line{
        Point st;
        Point ed;
        Line(){}
        Line(const Point &_st,const Point &_ed):st(_st),ed(_ed){}
        
        //�����߶εĳ��� 
        double Len(){
            return st.dis(ed);
        }
        
        //�ж��߶�a�Ƿ��ڴ��߶ε����� 
        bool IsBothSide(const Line &a)const{
            if(sign(dbcross(a.st,st,ed))*sign(dbcross(a.ed,st,ed))<=0){
                return true;
            }
            return false;
        }
        
        //�����ֱ��a��λ�ù�ϵ(0:�غ�,1ƽ��,2�ཻ)
        int check_pos(const Line &a)const{
            if(sign((ed-st).cross(a.ed-a.st))==0){
                if(sign(dbcross(st,a.st,a.ed))==0){
                    return 0;
                }
                return 1;
            }
            else{
                return 2;
            }
        }
        
        //������ֱ��a�Ľ���(�����������߶εĽ��㣬���������ж����߶��н���) 
        Point intersection(const Line &a)const{
            Point p1=st;
            Point p2=ed;
            Point q1=a.st;
            Point q2=a.ed;
            return p1+(p2-p1)*((q2-q1).cross(q1-p1)/(q2-q1).cross(p2-p1));
        }
    };
}

int N;
mygeo::Line line[2];

void solve(){
    int tmp=line[0].check_pos(line[1]);
    if(tmp==0){
        puts("LINE");
    }
    else if(tmp==1){
        puts("NONE");
    }
    else{
        mygeo::Point ans=line[0].intersection(line[1]);
        printf("POINT %.2lf %.2lf\n",ans.x,ans.y);
    }
}

int main(void){
    mygeo::Point st,ed;
    scanf("%d",&N);
    puts("INTERSECTING LINES OUTPUT");
    for(int i=1;i<=N;i++){
        scanf("%lf %lf %lf %lf",&st.x,&st.y,&ed.x,&ed.y);
        line[0]=mygeo::Line(st,ed);
        scanf("%lf %lf %lf %lf",&st.x,&st.y,&ed.x,&ed.y);
        line[1]=mygeo::Line(st,ed);
        solve();
    }
    puts("END OF OUTPUT");
    return 0;
}
