# include<iostream>
# include<cmath>

using namespace std;

const int maxsize=10001;
int num[maxsize];

int main(void){
	int m,i,count,j,ans;
	while(cin>>m){
		if(m==0)
		break;
		num[0]=2;
		count=1;
		ans=0; 
		for(i=3;i<=m;i++){
			for(j=2;j<=sqrt(i)+1;j++){
				if(i%j==0)
				break;
			}
			if(j>sqrt(i)+1)
				num[count++]=i;
		}
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				if(num[i]+num[j]==m)
					ans++;
			}		
	}
	cout<<ans<<endl;
	}
	return 0;
}
