# include<iostream>
# include<cstring>


# define maxsize 100000

using namespace std;

void solve(int *&num,const int &n){
	int i,j,u,temp1[maxsize],temp2[maxsize],op,xa;
	for(i=0;i<n;i++){
		memset(temp1,0,sizeof(int)*maxsize);
		memset(temp2,0,sizeof(int)*maxsize);
		op=0;
		xa=1;
		for(j=i-1;j>=0;j--){//Íù×ó±ßÃ¶¾Ù 
			if(num[i]>num[j])
			op++;
			else
			op--;
			if(!op)
			xa++;
			temp1[n+op]++;
		}
		op=0;
		for(j=i+1;j<n;j++){//ÍùÓÒ±ßÃ¶¾Ù 
			if(num[i]>num[j])
			op--;
			else
			op++;
			if(!op)
			xa++;
			temp2[n+op]++;
		}
		for(u=0;u<=(n+n/2+1);u++)
		xa=xa+temp1[u]*temp2[u];
		if(i==n-1)
		cout<<xa<<endl;
		else
		cout<<xa<<" "; 
	}
}

int main(void){
	int n,i;
	while(cin>>n){
		int *num=new int[n];
		for(i=0;i<n;i++){
			cin>>num[i];
		} 
		solve(num,n);
	}
	return 0;
}

