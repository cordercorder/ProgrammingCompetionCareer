# include<iostream>

using namespace std;

const int maxsize=1000002;

int next1[maxsize];

void getnext(const int &N,int *&num1){
	int j=1,k=0;
	next1[1]=0;
	while(j<=N){
		if(k==0||num1[j]==num1[k]){
			j++;
			k++;
			next1[j]=k;
		}
		else
		k=next1[k];
	}
}

int solve(int *&num1,int *&num2,const int &N,const int &M){
	int i=1,j=1;
	while(i<=N&&j<=M){
		if(j==0||num1[i]==num2[j]){
			i++;
			j++;
		}
		else
		j=next1[j];
	}
	//cout<<"i="<<i<<endl<<"j="<<j<<endl;
	if(j>M)
	return i-M;
	else
	return -1;
}

int main(void){
	int T,N,M,i;
	int num1[maxsize],num2[maxsize],*p1,*p2;
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(i=1;i<=N;i++)
		cin>>num1[i];
		for(i=1;i<=M;i++)
		cin>>num2[i];
		p1=num1;
		p2=num2;
		getnext(M,p2);
		cout<<solve(p1,p2,N,M)<<endl;
	}
	return 0;
} 
