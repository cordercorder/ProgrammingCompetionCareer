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
        double Len()const{
            return st.dis(ed);
        }
        
        //�ж��߶�a�Ƿ��ڴ��߶ε����� 
        bool IsBothSide(const Line &a)const{
            if(sign(dbcross(a.st,st,ed))*sign(dbcross(a.ed,st,ed))<=0){
                return true;
            }
            return false;
        }
        
        //ֱ����ֱ��֮��Ĺ�ϵ  �����ֱ��a��λ�ù�ϵ(0�غ�,1ƽ��,2�ཻ)
        int check_pos(const Line &a)const{
            if(sign((ed-st).cross(a.ed-a.st))==0){
                if(sign(dbcross(st,a.st,a.ed))==0){
                    return 0;
                }
                return 1;
            }
            return 2;
        }
        
        //�߶����߶�֮��Ĺ�ϵ  ������߶�a��λ�ù�ϵ(0������������,1�ĵ㹲�ߵ�û�н���,2ƽ��,3�ཻ�ڶ˵�,4��ͨ�ཻ,5û�н���)
        //�н���(0,3,4),��������޽���
        //Ӧ���ر�ע���߶ΰ��������,�߶ΰ���ʱӦ�ó����߶���ǰ,�̵��ں� 
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
        
        //�ж��߶�֮��Ĺ�ϵ(�򻯰�)
        //0�н���(���������ȷ��,�����ཻ�ڶ˵�),1�ĵ㹲�ߵ�û�н���,2���߶�ƽ��, 3��һ������,4û�н���
        //0,3�н���,��������޽��� 
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
