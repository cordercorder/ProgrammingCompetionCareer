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
			sum=num[i]-num[i-1]-1+sum;//����һ��������Ŀ�϶Ϊn-1������������ȥ��ǰ������������һ�ε����� 
		}		
		cout<<sum-min(num[1]-num[0]-1,num[N-1]-num[N-2]-1)<<endl;
	}
	return 0;
}
