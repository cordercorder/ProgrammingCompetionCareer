# include<stdio.h>
# include<string.h>

# define maxsize 102

void Handle(int *num,int *num1,int *num2,char *str1,char *str2){
	int i,j,k,n1=strlen(str1),n2=strlen(str2);
	int out,count,temp,result;
	int op[maxsize];
	memset(num,0,sizeof(int)*2*maxsize);
	for(i=0;i<n1;i++){
		num1[i]=str1[n1-i-1]-'0';//将字符转换为数字 
	}
	for(i=0;i<n2;i++){
		num2[i]=str2[n2-i-1]-'0';
	}
	for(i=0;i<n1;i++){
		out=0;
		count=0;
		for(j=0;j<n2;j++){
			temp=num1[i]*num2[j]+out;
			result=temp%10;
			out=temp/10;
			op[count++]=result;
			if(j==n2-1&&out!=0){
				op[count++]=out;
			}
		}
		out=0;
		for(k=i,j=0;k<count+i;k++,j++){
			temp=num[k]+op[j]+out;
			result=temp%10;
			out=temp/10;
			num[k]=result;
			if(k==count+i-1&&out!=0){
				num[++k]=out;
			}
		}
	}
	for(i=k-1;i>0&&num[i]==0;i--);//除去开头的0 
	for(j=i;j>=0;j--)
	printf("%d",num[j]);
	printf("\n");
}

int main(void){
	char str1[maxsize],str2[maxsize];
	int num1[maxsize],num2[maxsize],num[2*maxsize];
	while(scanf("%s %s",str1,str2)!=EOF){
		Handle(num1,num2,num,str1,str2);
	}
	return 0;
}


