# include<iostream>
# include<algorithm>
# include<cmath>

using namespace std;

int main(void){
	int n,i,sum1=0,sum2=0;
	cin>>n;
	int *num=new int[n];
	for(i=0;i<n;i++)
	cin>>num[i];
	sort(num,num+n);
	for(i=0;i<n/2;i++)
	sum1=sum1+num[i];
	for(;i<n;i++)
	sum2=sum2+num[i];
	if(n%2==0){
		cout<<(sum1<sum2?sum1:sum2)<<" "<<(sum1>sum2?sum1:sum2)<<endl;
	}
	else{
		if(fabs(sum1-sum2)<=fabs((sum1+num[n/2])-(sum2-num[n/2]))){
			cout<<(sum1<sum2?sum1:sum2)<<" "<<(sum1>sum2?sum1:sum2)<<endl;
		}
		else{
			sum1=sum1+num[n/2];
			sum2=sum2-num[n/2];
			cout<<(sum1<sum2?sum1:sum2)<<" "<<(sum1>sum2?sum1:sum2)<<endl;
		}
	}
	delete [] num; 
	return 0;
}
