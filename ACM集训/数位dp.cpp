# include<iostream>

using namespace std;

int a[1000000];
char str[8];

bool Check(int x){
	int i,count=0;
	while(x){
		str[count++]=(x%10)+48;
		x=x/10;
	}
	str[count]='\0';
	if(str[0]=='4')
	return 0;
	for(i=0;i<count-1;i++){
		//cout<<"str="<<str[i]<<endl;
		if(str[i]=='4'||str[i+1]=='4'){
			return 0;
		}
		else if(str[i]=='2'&&str[i+1]=='6')
		return 0;
	}
	//cout<<"str="<<str<<endl;
	return 1;
}

void Sum(int &sum){
	int i;
	for(i=1;i<1000001;i++){
		if(Check(i))
		sum++;
		a[i]=sum;
	}
}

int main(void){
	int n,m,sum,flag=0;
	while(cin>>n>>m){
		if(n==0&&m==0)
		break;
		if(flag==0){
			Sum(sum);
			flag=1;
		}
			if(Check(n))
			cout<<a[m]-a[n]+1<<endl;
			else
			cout<<a[m]-a[n]<<endl;
	}
	return 0;
} 
