# include<iostream>
# include<algorithm>
# include<cmath> 

using namespace std;

bool check(const int &m){
	int i;
	if(m==2)
	return 1;
	for(i=2;i<=sqrt(m)+1;i++)
	if(!(m%i))
	return 0;
	return 1;
}

int main(void){
	int N,k,i,m,temp;
	cin>>N>>k;
	int *num=new int[N];
	for(i=0;i<N;i++)
	cin>>num[i];
	sort(num,num+N);
	m=num[N-k]-num[k-1];
	if(m<0)
	temp=-m;
	else
	temp=m;
	if(check(temp))
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	cout<<m<<endl;
	return 0;
} 
