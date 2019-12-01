# include<iostream>

using namespace std;

void Qmod(long long a,long long b,long long c){
	long long ans=1;
	while(b){
		if(b%2==1){
			ans=(ans*a)%c;
		}
		b=b/2;
		a=(a*a)%c;
	}
	printf("%lld\n",ans);
}

int main(void){
	long long a,b,c;
	while(cin>>a>>b>>c){
		cout<<a<<"^"<<b<<" mod "<<c<<"=";
		Qmod(a,b,c);
	}
	return 0;
}
