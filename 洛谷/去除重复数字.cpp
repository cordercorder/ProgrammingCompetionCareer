# include<iostream>
# include<algorithm>

using namespace std;

void solve(int *&num,const int &n){
	int i,count=0,flag;
	int *temp=new int[n];
	for(i=0;i<n;){
		flag=0;
		if(i<n-1&&num[i]==num[i+1]){
			flag=1;
		}
		while(i<n-1&&num[i]==num[i+1]&&flag)
			i++;
			if(flag){
				continue;
			}
		temp[count++]=num[i++];
	}
	cout<<count<<endl;
	cout<<num[0];
	for(i=1;i<count;i++)
		cout<<" "<<temp[i];
	cout<<endl;
}

int main(void){
	int n,i;
	cin>>n;
	int *num=new int [n];
	for(i=0;i<n;i++)
		cin>>num[i];
	sort(num,num+n);
	solve(num,n);
	return 0;
}
