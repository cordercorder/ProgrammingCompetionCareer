# include<iostream>

using namespace std;

int gcd(int a,int b){
	if(b==0)
	return a;
	return gcd(b,a%b);
}


int main(void){
	int a,b;
	while(cin>>a>>b){
		cout<<gcd(a,b)<<endl;
	}
	return 0;
} 
