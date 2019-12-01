# include<stdio.h>
# include<string.h>
# include<stdlib.h>

# define Maxsize 20


int data[Maxsize],*num;
int top;


void combination(int s,int n,int m){
	if(s>n)
	return ;
	if(top==m){
		int i;
		for(i=0;i<m-1;i++)
		printf("%d ",data[i]);
		printf("%d\n",data[i]);
		return ;
	}
	data[top++]=num[s];
	combination(s+1,n,m);
	top--;
	combination(s+1,n,m);
}

int main(void){
	int n,i;
	while(scanf("%d",&n)){
		if(n==0)
		break;
		num=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		scanf("%d",&num[i]);
		combination(0,n,6);
		printf("\n");		
	}
	return 0;
} 
