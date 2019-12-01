# include<iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;
	while(n){
		cout<<"n="<<n<<endl;
		n=n>>1;
	}
	return 0;
} 
