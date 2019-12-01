# include<iostream>

using namespace std;

int Q(int a,int b){
	if(a%b==0)
	return b;
	return Q(b,a%b);
}//求两个数的最大公约数 

int main(void){
	int t,n,a,b,x,sum=0;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		sum++;
		x=Q(a,b);
		cout<<"Case #"<<sum<<": ";
		if(a==1||b==1||x==1){
			if(n%2)
			cout<<"Yuwgna"<<endl;
			else
			cout<<"Iaka"<<endl;
		}
		else{
			n=n/x;
			if(n%2)
			cout<<"Yuwgna"<<endl;
			else
			cout<<"Iaka"<<endl;
		}
	}
	return 0;
}
