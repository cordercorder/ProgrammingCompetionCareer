# include<iostream>

using namespace std;


typedef struct node{
	int op;
	int x;
	int y;
}node;
 
const int maxsize=50001;
int *parent;


int Find(int x){
	while(parent[x]!=x){
		x=parent[x];
	}
	return x;
}


bool Union(const int &x,const int &y){
	int nx=Find(x),ny=Find(y);
	if(nx==ny)
	return 0;
	parent[ny]=nx;
	return 1;
}





int main(void){
	int N,K,i;
	int nop,nx,ny;
	int ans=0,count=0;
	node num[maxsize];
	cin>>N>>K;
	parent=new int[N+1];
	for(i=1;i<=N;i++)
	parent[i]=i;	
	while(K--){
		cin>>nop>>nx>>ny;
		if(nx>N||ny>N){
			ans++;
		}
		else if(nop==2&&(nx==ny)){
			ans++;
		}
		else if(nop==1){
			ans++;
		}
		else{
			num[count].op=nop;
			num[count].x=nx;
			num[count++].y=ny;
			if(Union(nx,ny)){
				ans++;
			}
		}
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
}
