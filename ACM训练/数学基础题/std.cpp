#include <iostream>
#include <vector>
#include <algorithm>
#include<stdio.h>

#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out2.txt","w",stdout)

using namespace std;
 
//��չŷ����� 
//��ⷽ��ax+by=gcd(a,b)  d=gcd(a,b) 
void ex_gcd(long long a,long long b,long long &d,long long &x,long long &y)
{//gcd(a,0)=1*a+0*0  �ݹ���� 
	if(b==0)
	{
		d=a;
		x=1;
		y=0;
	}
	else
	{
		ex_gcd(b,a%b,d,y,x);
		y=y-x*(a/b);//�ȼ�ס 
	}
}
 
long long slove()
{
	//��ax+by=n+1�ж�����������
	long long x,y,a,b,n,d;
	cin>>n>>a>>b;
	//��ⷽ��ax+by=gcd(a,b)  d=gcd(a,b) 
	ex_gcd(a,b,d,x,y);
	long long z=a*b/d;   //��С������ 
	//n+1������gcd(a,b)�ı��� 
	if((n+1)%d)
	  return 0;
	x=x*((n+1)/d); //��� ax+by=n+1  x 
	long long r=b/d;
	x=(x%r+r)%r;//�����С��x
	if(x==0)  x=r;	
	long long remain=n-x*a;
	long long ans=0;
	if(remain<0)
	     return 0;
	else
	{
	   ans=1;            //��Сx��
	                      //remain/Lcm��a,b�����ǿ����ж��ٸ� ab���� 
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
