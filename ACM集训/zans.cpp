# include<iostream>
# include<algorithm>

using namespace std;

const int maxsize=1001;

void solve(int *num,const int &n){
	int i,j,max=-1,sum,location,count;
	for(i=0;i<n;i++){
		sum=0;
		for(count=0,j=i;count<4;j++,count++){
			sum=sum+num[j%n];
		}
		if(sum>max){
			max=sum;
			location=i;
		}
	}
	cout<<location+1<<endl;
}

int main(void){
	int num[maxsize];
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>num[i];
	solve(num,n);
	return 0;
}

