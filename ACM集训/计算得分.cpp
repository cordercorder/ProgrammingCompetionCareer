# include<iostream>
# include<algorithm>
# include<cstdio>

using namespace std;

const int maxsize=102;

int n;
int num[maxsize];

void Ave(double &ave){
	int i;
	ave=0;
	for(i=1;i<n-1;i++){
		ave=ave+num[i];
	}
	ave=ave/(n-2);
}

int main(void){
	int i;
	double ave;
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>num[i];
		sort(num,num+n);
		Ave(ave);
		printf("%.2lf\n",ave);
	}
	return 0;
}
