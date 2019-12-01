# include<iostream>

using namespace std;

const int maxsize=100005;

int num[maxsize];
int n,m;

bool check(int lim){
	int sum=0,cnt=1,i;
	for(i=0;i<n;i++){
		if(num[i]>lim)
			return 1;
		if(sum+num[i]<=lim)
			sum=sum+num[i];
		else{
			sum=num[i];
			cnt++;
		}	
	}
	if(cnt>m)
		return 1;//说明分的组太多了，需要往更大的分 
	else
		return 0;//说明分的组的个数够了，接下来要慢慢逼近最小值 
}

int main(void){
	int l,r,mid,s=0,temp,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		s=s+num[i];
	}
	l=0,r=s;
	while(l<r){//二分模板   l为下界，r为上界  求下界变下界，求上界变上界 
		mid=(l+r)>>1;//分为每段不超过mid的若干段
		//printf("mid=%d\n",mid);
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	printf("%d\n",l);
	return 0;
}
