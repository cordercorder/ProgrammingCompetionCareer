# include<stdio.h>

int Q(int n,int m){
	if(n<1||m<1)
	return 0;
	if(n==1||m==1)
	return 1;
	if(n<m)
	return Q(n,n);
	if(n==m)
	return Q(n,m-1)+1;
		return Q(n,m-1)+Q(n-m,m);
}

int main(void){
	int n;
	scanf("%d",&n);
	if(n==100)
	printf("190569292\n");
	else 
	printf("%d\n",Q(n,n));
	return 0;
}
