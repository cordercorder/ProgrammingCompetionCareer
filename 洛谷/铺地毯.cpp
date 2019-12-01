# include<iostream>

using namespace std;

typedef struct node{
	int x;
	int y;
	int x_len;
	int y_len;
}node;

int solve(node *&num,const int &n,const int &nx,const int &ny){
	int i;
	for(i=n-1;i>=0;i--){
		if(nx>=num[i].x&&nx<=num[i].x+num[i].x_len&&ny>=num[i].y&&ny<=num[i].y_len+num[i].y){
			return i+1;
		}
	}
	return -1;
}

int main(void){
	int n,i,nx,ny;
	cin>>n;
	node *num=new node[n];
	for(i=0;i<n;i++){
		cin>>num[i].x>>num[i].y>>num[i].x_len>>num[i].y_len;
	}
	cin>>nx>>ny;
	cout<<solve(num,n,nx,ny)<<endl;
	return 0;
} 
