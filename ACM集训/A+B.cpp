# include<iostream>
# include<cstring>

# define maxsize 10002

using namespace std;



void Handle(int *num,int *num1,int *num2,char *str1,char *str2){
	int i,j,n1=strlen(str1),n2=strlen(str2),n=(n1>n2?n1:n2);
	int result,out=0,temp,count=0;
	memset(num1,0,sizeof(int)*maxsize);
	memset(num2,0,sizeof(int)*maxsize);
	for(i=0;i<n1;i++){
		num1[i]=str1[n1-i-1]-'0';
	}
	for(i=0;i<n2;i++){
		num2[i]=str2[n2-i-1]-'0';
	}
	for(i=0;i<n;i++){	
		temp=num1[i]+num2[i]+out;
		result=temp%10;
		out=temp/10;
		num[count++]=result;
		if(i==n-1&&out!=0){
			num[count++]=out;
		}
	}
	for(i=count-1;i>0&&num[i]==0;i--);
	
	cout<<str1<<" + "<<str2<<" = ";
	for(;i>=0;i--)
	cout<<num[i];
}

int main(void){
	char str1[maxsize],str2[maxsize];
	int T,num[maxsize],num1[maxsize],num2[maxsize],sum=0;
	cin>>T;
	while(T--){
		cin>>str1>>str2;
		sum++;
		cout<<"Case "<<sum<<":"<<endl;
		Handle(num,num1,num2,str1,str2);	
		cout<<endl;
		if(T)
		cout<<endl;
	}
	return 0;
}

