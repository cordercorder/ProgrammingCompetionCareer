# include<iostream>
# include<cstdio>
# include<algorithm>

using namespace std;

int main(void){
	int n,i;
	while(cin>>n){
		if(n==0)
		break;
		int *num=new int[n];
		for(i=0;i<n;i++)
		cin>>num[i];
		sort(num,num+n);
		cout<<num[n-1]<<endl;
		delete [] num;
	}
	return 0;
}

