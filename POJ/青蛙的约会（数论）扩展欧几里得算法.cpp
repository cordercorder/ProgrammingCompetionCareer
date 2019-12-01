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

typedef long long ll;

using namespace std;

ll x,y,m,n,l;

ll Abs(ll a){
	if(a>0)
		return a;
	return -a;
}

ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int r,t;
	r=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-(a/b)*y;
	return r;
}

int main(void){
	ll i,a,b,c,g,xx,yy,t;
	while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)!=EOF){
		a=m-n;
		b=l;
		c=y-x;
		if(a<0){
			a=-a;
			c=-c;
		}
		g=exgcd(a,b,xx,yy);
		//printf("a=%lld  b=%lld  c=%lld\n",a,b,c);
		//printf("xx=%lld  yy=%lld\n",xx,yy);
		if(c%g!=0){
			printf("Impossible\n");
			continue;
		}
		xx=xx*(c/g);
		t=b/g;
		if(xx>0){
			xx=xx%t;
		}
		else{
			xx=xx%t+t;
		}
		printf("%lld\n",xx); 
	}
	return 0;
}
