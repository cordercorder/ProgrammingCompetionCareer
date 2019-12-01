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
        //������
        db dot(const Point &a)const{
            return x*a.x+y*a.y;
        }
        //������
        db cross(const Point &a)const{
            return x*a.y-y*a.x;
        }
        //������������
        db dis(const Point &a)const{
            db ans=(x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);
            return sqrt(ans);
        } 
        //��ʱ����תangle
        Point rotate(db angle){
            return Point(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
        }
        //��ʱ����ת90�� 
        Point ratate90(){
            return Point(-y,x);
        }
    };
    
    //����p0p1���p0p2,���������ж����㹲�� 
    db dbcross(const Point &p0,const Point &p1,const Point &p2){
        return (p1-p0).cross(p2-p0); 
    }
    
    //���Կ�����㵽�յ��һ������ 
    struct Line{
        Point st;//��� 
        Point ed;//�յ� 
        db angle;//�Ƕ� [-180, 180]
        Line(){}
        Line(const Point &_st,const Point &_ed):st(_st),ed(_ed){}
        
        void get_angle(){
            angle=atan2(ed.y-st.y,ed.x-st.x);
        }
        
        //�жϵ�a�Ƿ������������,1(a��ֱ�����),-1(a��ֱ���ұ�),0(a��ֱ�߹���) 
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
        
        //������������Ľ��Ϊ3,4,1,2���� 
        bool operator<(const Line &a)const{
            int x=sign(angle-a.angle);
            if(x==0){//������ֱ�߽Ƕ���ͬʱ,��ߵ��߶�����ǰ�� 
                return a.toLeftTest(st)==1;
            }
            return x<0;
        }
        
        //�����߶εĳ��� 
        db Len()const{
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
        
        //����һ������ֱ�߽���ĺ���,����֧�ְ�ƽ��ռ佻���� 
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
    
    //��ֱ�߼���l�İ�ƽ��ռ佻,����l�е�ֱ��Ӧ����ʱ�����,����Ҫq��ip������l��С���Ƶ�������Ϊ���� 
    //ע��ʹ��get_angle���� 
    //������ֱ�ߵİ�ƽ�潻������,�����Կ�������ε�ÿһ������ 
    db half_plane(Line *l,Line *q,Point *ip,int N){
        sort(l+1,l+1+N);//�������� 
        int tot=1;
        for(int i=2;i<=N;i++){
            if(sign(l[i].angle-l[tot].angle)==1){//����������ͬ���������ߵ��߶� 
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
        
        if(tail-head+1<=2){//��ʾ�˶���β����ں��� 
            return 0;
        }
        //���濪ʼ����� 
        tot=0;
        for(int i=head;i<tail;i++){
            ip[++tot]=q[i].crosspoint(q[i+1]);
        }
        ip[++tot]=q[head].crosspoint(q[tail]);
        db ans=0;
        for(int i=3;i<=tot;i++){
            ans+=(ip[i-1]-ip[1]).cross(ip[i]-ip[1]);
        }
        return ans/2.0;
    }
    
    //��͹����������,����о���������Ҫ����sign���� 
    bool cmp_x(const Point &a,const Point &b){
        if(a.x<b.x)
            return true;
        else if(a.x==b.x&&a.y<b.y)
            return true;
        return false;
    }
    
    //��͹��,�±��0��ʼ,���ص�͹���ϵĵ�����ʱ������ 
    vector<Point> convex_hull(Point *ps,int n){
        sort(ps,ps+n,cmp_x);
        int k=0;//͹��������
        vector<Point> qs(2*n);
        //����͹���ϲ� 
        for(int i=0;i<n;i++){
            //����о���������Ҫ����sign����,��ͬ 
            while(k>1&&(qs[k-1]-qs[k-2]).cross(ps[i]-qs[k-1])<=0){
                k--;
            }
            qs[k++]=ps[i];
        }
        //����͹���²� 
        for(int i=n-2,t=k;i>=0;i--){
            while(k>t&&(qs[k-1]-qs[k-2]).cross(ps[i]-qs[k-1])<=0){
                k--;
            }
            qs[k++]=ps[i];
        }
        qs.resize(k-1);
        return qs;
    }
    
    //��ת������͹����������������,�±��0��ʼ 
    db rotating_calipers(Point *p,int n){
        db ans=0;
        for(int i=0;i<n;i++){
            int j=(i+1)%n;
            int k=(j+1)%n;
            while(j!=i&&k!=i){
                ans=max(ans,abs((p[j]-p[i]).cross(p[k]-p[i])));
                while(sign((p[i]-p[j]).cross(p[(k+1)%n]-p[k]))<0)
                    k=(k+1)%n;
                j=(j+1)%n;
            }
        }
        return ans/2.0;
    }
}

const int maxn=50010;

int N;
mygeo::Point p[maxn],p2[maxn];

int main(void){
    while(scanf("%d",&N)){
        if(N==-1)
            break;
        for(int i=0;i<N;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        vector<mygeo::Point> con=convex_hull(p,N);
        for(int i=0;i<(int)con.size();i++){
            p2[i]=con[i];
        }
        printf("%.2f\n",mygeo::rotating_calipers(p2,(int)con.size()));
    }
    return 0;
}
