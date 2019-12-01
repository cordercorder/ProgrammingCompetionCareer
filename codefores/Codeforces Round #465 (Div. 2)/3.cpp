# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

struct node{
	double x;
	double y;
};

node ans1,ans2,ans3,ans4;

double r,x_1,y_1,x2,y2;

double dis(const double &x1,const double &y1,const double &x2,const double &y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(void){
	int i;
	node tmp;
	double a,b;
	while(scanf("%lf %lf %lf %lf %lf",&r,&x_1,&y_1,&x2,&y2)!=EOF){
		if(dis(x_1,y_1,x2,y2)>=r*r){
			printf("%.16lf %.16lf %.16lf\n",x_1,y_1,r);
		}
		else{
			if(x_1==x2&&y_1!=y2){
				tmp.x=x_1;
				tmp.y=y_1-r;
				ans1.x=x_1;
				ans1.y=y_1+r;
				if(dis(x2,y2,ans1.x,ans1.y)>dis(x2,y2,tmp.x,tmp.y)){
					printf("%.16lf %.16lf %.16lf\n",(ans1.x+x2)/2,(ans1.y+y2)/2,sqrt(dis(x2,y2,ans1.x,ans1.y))/2);
				}
				else{
					printf("%.16lf %.16lf %.16lf\n",(tmp.x+x2)/2,(tmp.y+y2)/2,sqrt(dis(x2,y2,tmp.x,tmp.y))/2);
				}
			}
			else if(x_1!=x2&&y_1==y2){
				tmp.x=x_1+r;
				tmp.y=y_1;
				ans1.x=x_1-r;
				ans1.y=y_1;
				if(dis(x2,y2,ans1.x,ans1.y)>dis(x2,y2,tmp.x,tmp.y)){
					printf("%.16lf %.16lf %.16lf\n",(ans1.x+x2)/2,(ans1.y+y2)/2,sqrt(dis(x2,y2,ans1.x,ans1.y))/2);
				}
				else{
					printf("%.16lf %.16lf %.16lf\n",(tmp.x+x2)/2,(tmp.y+y2)/2,sqrt(dis(x2,y2,tmp.x,tmp.y))/2);
				}
			}
			else if(x_1==x2&&y_1==y2){
				printf("%.16lf %.16lf %.16lf\n",(2*x_1-r)/2,y_1,r/2);
			}			
			else{
				a=x2-x_1;
				b=y2-y_1;
				tmp.x=x_1+(r*a)/(sqrt(a*a+b*b));
				tmp.y=y_1+(r*b)/(sqrt(a*a+b*b));
				ans1.x=x_1-(r*a)/(sqrt(a*a+b*b));
				ans1.y=y_1-(r*b)/(sqrt(a*a+b*b));
				if(dis(x2,y2,ans1.x,ans1.y)>dis(x2,y2,tmp.x,tmp.y)){
					printf("%.16lf %.16lf %.16lf\n",(ans1.x+x2)/2,(ans1.y+y2)/2,sqrt(dis(x2,y2,ans1.x,ans1.y))/2);
				}
				else{
					printf("%.16lf %.16lf %.16lf\n",(tmp.x+x2)/2,(tmp.y+y2)/2,sqrt(dis(x2,y2,tmp.x,tmp.y))/2);
				}
			}
		}
	}
	return 0;
}
