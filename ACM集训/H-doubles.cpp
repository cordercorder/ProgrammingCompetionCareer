# include<iostream>

# define maxsize 16

using namespace std;

int num[maxsize];

int solve(const int &count){
	int i,j,sum=0;
	for(i=0;i<count;i++){
		for(j=i+1;j<count;j++){
			if(num[i]==num[j]*2||num[j]==num[i]*2)
			sum++;
		}
	}
	return sum;
}

int main(void){
	int i,x,count;
	while(cin>>x){
		if(x==-1)
		break;
		count=1;
		num[0]=x;
		while(cin>>x){
			if(x)
			num[count++]=x;
			else
			break;
		}
		cout<<solve(count)<<endl;
	}
	return 0;
}
