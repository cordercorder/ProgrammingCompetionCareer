# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define Maxsize 102

int num[Maxsize][Maxsize];
int F[Maxsize];

int main(void){
	int n,i,j,k,max,sum;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		scanf("%d",&num[i][j]);
		max=-1000000;
		for(i=0;i<n;i++){
			memset(F,0,sizeof(int)*Maxsize);
			for(j=i;j<n;j++){
				sum=0;
				for(k=0;k<n;k++){
					F[k]=F[k]+num[j][k];//j限制了矩阵的行数 
					if(sum>0)
					sum=sum+F[k];//sum是最大的子阵 
					else
					sum=F[k];
					if(sum>max)
					max=sum; 
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
