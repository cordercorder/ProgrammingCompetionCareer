# include<iostream>

using namespace std;

bool solve(const int &n){
	if(n<=1)
	return 0;
	int m=n-2;
	if(!(m%4))
	return 1;
	return 0;
}
int main(void){	
	int n;
	while(cin>>n){
		if(solve(n))
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;		
	}
	return 0;
}
