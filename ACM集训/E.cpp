# include<iostream>
# include<algorithm>

using namespace std;

int main(void){
	int t,N,*num,*num1,i,sum;
	cin>>t;
	while(t--){
		cin>>N;
		num=new int[N];
		num1=new int[N-1];
		sum=0;
		for(i=0;i<N;i++){
			cin>>num[i];
			if(i>0)
			sum=num[i]-num[i-1]-1+sum;//兔子一定会跳完的空隙为n-1，接下来就是去最前面或者最后面那一段的问题 
		}		
		cout<<sum-min(num[1]-num[0]-1,num[N-1]-num[N-2]-1)<<endl;
	}
	return 0;
}
