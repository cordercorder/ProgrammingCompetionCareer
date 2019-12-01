# include<iostream>

using namespace std;

int *num; 

/*int solve(int *&num,const int &m,const int &n){
	int i,sum=0;
	for(i=0;i<n;i++){
		if(num[i]<m)
		sum++;
	}
	return sum;
}*/ 

int main(void){
	int M,N,i,sum;
	while(cin>>M>>N){
		num=new int[N];
		sum=0;
		for(i=0;i<N;i++){
			cin>>num[i];
			if(num[i]<M)
			sum++;
		}
		cout<<sum<<endl; 
		delete [] num;
	}
	return 0;
}
