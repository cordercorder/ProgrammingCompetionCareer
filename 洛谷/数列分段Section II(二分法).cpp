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
		return 1;//˵���ֵ���̫���ˣ���Ҫ������ķ� 
	else
		return 0;//˵���ֵ���ĸ������ˣ�������Ҫ�����ƽ���Сֵ 
}

int main(void){
	int l,r,mid,s=0,temp,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		s=s+num[i];
	}
	l=0,r=s;
	while(l<r){//����ģ��   lΪ�½磬rΪ�Ͻ�  ���½���½磬���Ͻ���Ͻ� 
		mid=(l+r)>>1;//��Ϊÿ�β�����mid�����ɶ�
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
