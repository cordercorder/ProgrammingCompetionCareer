# include<iostream>
# include<algorithm>
# include<cmath>

using namespace std;

int min(int a,int b,int c){
	if(a<b){
		if(a<c)
		return 1;
		else
		return 3;
	}
	else{
		if(b<c)
		return 2;
		else
		return 3;
	}
}


int solve(const int &N,const int &k){
	int x=N,ans=0;
	while(x!=k){
		if(min(abs(2*x-k),abs(x+1-k),abs(x-1-k))==1){
			x=2*x;
			ans++;
		}
		else if(min(abs(2*x-k),abs(x+1-k),abs(x-1-k))==2){
			x=x+1;
			ans++;
		}
		else{
			x=x-1;
			ans++;
		}
	}
	return ans;
}

int main(void){
	int N,K;
	while(cin>>N>>K){
		cout<<solve(N,K)<<endl;
	}
	return 0;
}
