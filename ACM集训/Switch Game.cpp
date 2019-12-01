# include<iostream>

using namespace std;

bool check(const int &n){
	int i,ans=0;
	for(i=1;i<=n;i++){
		if(!(n%i)){
			ans++;
		}
	}
	//cout<<"ans="<<ans<<endl;
	if(ans%2)
	return 1;
	else
	return 0;
} 

int main(void){
	int n;
	while(cin>>n){
		if(check(n))
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}
	return 0;
} 
