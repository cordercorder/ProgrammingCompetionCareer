# include<iostream>

using namespace std;

bool Check(int x,char *str){
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

void Sum(const int &n,const int &m,int &sum){
	int i;
	char str[8];
	for(i=n;i<=m;i++){
		if(Check(i,str))
		sum++;
	}
}

int main(void){
	int n,m,sum;
	while(cin>>n>>m){
		if(n==0&&m==0)
		break;
		sum=0;
		Sum(n,m,sum);
		cout<<sum<<endl;
	}
	return 0;
} 
