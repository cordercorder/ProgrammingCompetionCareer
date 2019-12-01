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

using namespace std;

const int maxsize=1e3+5;

struct node{
	int num[maxsize];
	int len;
	node operator *(const node &a){
		int c[maxsize];
		int temp[maxsize],len;
		memset(c,0,sizeof(c));
		int i,j,res,ans,out,cnt;
		for(i=0;i<a.len&&i<500;i++){
			out=0;
			cnt=0;
			for(j=0;j<this->len&&j<500;j++){
				res=a.num[i]*this->num[j]+out;
				ans=res%10;
				out=res/10;
				temp[cnt++]=ans;
			}
			if(out){
				temp[cnt++]=out;
			}
			//printf("cnt=%d\n",cnt);
			out=0;
			for(j=0;j<cnt;j++){
				res=c[i+j]+temp[j]+out;
				ans=res%10;
				out=res/10;
				c[i+j]=ans;
			}
			if(out){
				c[i+j]=out;
				len=i+j+1;
			}
			else{
				len=i+j;
			}
		}
		//printf("c=%d\n",c[1]);
		//printf("len=%d\n",len);
		//for(i=0;i<len;i++){
		//	printf("%d",c[i]);
		//}
		//printf("\nok\n");
		memcpy(this->num,c,sizeof(int)*len);
		this->len=len;
		return *this;
	}
};

node a,b,c;
int p;

int main(void){
	int i,x;
	scanf("%d",&p);
	x=p*log10(2)+1;//ÇóÎ»Êý 
	printf("%d\n",x);
	b.num[0]=1;
	b.len=1;
	a.num[0]=2;
	a.len=1;
	while(p){
		if(p&1){
			b=b*a;
		}
		p=p/2;
		a=a*a;
	}
	//printf("the len is %d\n",(a*b).len);
	//c=a*b;
	//for(i=c.len-1;i>=0;i--){
	//	printf("%d",c.num[i]);
	//}
	//printf("\n");
	b.num[0]--;
	for(i=499;i>=0;i--){
		if(i>=b.len){
			printf("0");
		}
		else{
			printf("%d",b.num[i]);
		}
		if(i!=0&&i%50==0){
			printf("\n");
		}
	}
	return 0;
}
