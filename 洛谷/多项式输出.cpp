# include<iostream>
# include<cmath>

using namespace std;

void solve(int *&num,const int &n){
	int i,count;
	for(count=n;count>0&&num[count]==0;count--);
	if(count!=0&&num[count]==1)
	cout<<"x^"<<count;
	else if(count!=0&&num[count]==-1)
	cout<<"-"<<"x^"<<count;
	else if(count!=0&&num[count])
	cout<<num[count]<<"x^"<<count;
	//cout<<"count="<<count<<endl;
	for(i=count-1;i>1;i--){
		if(num[i]>0){
			if(num[i]!=1)
			cout<<"+"<<num[i]<<"x^"<<i;
			else
			cout<<"+"<<"x^"<<i;
		}
		else if(num[i]<0){
			if(num[i]!=-1)
				cout<<num[i]<<"x^"<<i;
				else
				cout<<"-"<<"x^"<<i;
		}
	}
	if(num[1]>0){
		if(num[1]!=1)
			cout<<"+"<<num[1]<<"x";
			else
			cout<<"+"<<"x";
	}
	else if(num[1]<0){
			if(num[1]!=-1)
				cout<<num[1]<<"x";
				else
				cout<<"-"<<"x";
		}
	if(num[0]>0){
		if(count==0){
			cout<<num[0]<<endl;
		}
		else{
			cout<<"+"<<num[0]<<endl;
		}
	}
	else if(num[0]<0){
		cout<<num[0]<<endl;
		}
}

int main(void){
	int n,i,sum=0;
	cin>>n;
	int *num=new int[n+1];
	for(i=n;i>=0;i--){
		cin>>num[i];
		sum=sum+abs(num[i]);
	}
	if(sum)
	solve(num,n);
	else
	cout<<"0"<<endl;
	return 0;	
}
