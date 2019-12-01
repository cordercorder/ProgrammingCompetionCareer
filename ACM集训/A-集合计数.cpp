# include<iostream>

using namespace std;

int N,A,B;

void solve(int &sum){
	int i; 
	for(i=1;i<=N;i++){
		if((i%A)==0&&((N-i+1)%B)==0){
		sum++;
	}
}
}

int main(void){
	int T,sum;
	cin>>T;
	while(T--){
		cin>>N>>A>>B;
		sum=0;
		solve(sum);
		cout<<sum<<endl;
	}
	return 0;
}
