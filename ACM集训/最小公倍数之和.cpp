# include<iostream>


using namespace std;

long long gcd(int a,int b){
	if(b==0)
	return a;
	return gcd(b,a%b);
}

void solve(long long &result,const int &n){
	int i,temp;
	for(i=1;i<=n;i++){
		temp=gcd(i,n);
		result=result+(i*n)/temp;
	}
}

int main(void){
	int T,i,n;
	long long result;
	cin>>T;
	while(T--){
		cin>>n;
		result=0;
		solve(result,n);
		cout<<result%1000000007<<endl;
	}
	return 0;
}
