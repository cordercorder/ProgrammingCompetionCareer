#include <iostream>
#include <vector>
#include <algorithm>
#include<stdio.h>

#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out2.txt","w",stdout)

using namespace std;
 
//扩展欧几里德 
//求解方程ax+by=gcd(a,b)  d=gcd(a,b) 
void ex_gcd(long long a,long long b,long long &d,long long &x,long long &y)
{//gcd(a,0)=1*a+0*0  递归出口 
	if(b==0)
	{
		d=a;
		x=1;
		y=0;
	}
	else
	{
		ex_gcd(b,a%b,d,y,x);
		y=y-x*(a/b);//先记住 
	}
}
 
long long slove()
{
	//求ax+by=n+1有多少组整数解
	long long x,y,a,b,n,d;
	cin>>n>>a>>b;
	//求解方程ax+by=gcd(a,b)  d=gcd(a,b) 
	ex_gcd(a,b,d,x,y);
	long long z=a*b/d;   //最小公倍数 
	//n+1必须是gcd(a,b)的倍数 
	if((n+1)%d)
	  return 0;
	x=x*((n+1)/d); //求解 ax+by=n+1  x 
	long long r=b/d;
	x=(x%r+r)%r;//求解最小的x
	if(x==0)  x=r;	
	long long remain=n-x*a;
	long long ans=0;
	if(remain<0)
	     return 0;
	else
	{
	   ans=1;            //最小x解
	                      //remain/Lcm（a,b）就是看看有多少个 ab倍数 
	   ans=ans+remain/z;
	}
	return ans;
}
int main()
{
	FIN;
	FOUT;
   int t;
   //ios::sync_with_stdio(false);
   cin>>t;
   while(t--)
   {
   	  long long ans=slove();
   	  cout<<ans<<endl;
   }	
   return 0;
}
