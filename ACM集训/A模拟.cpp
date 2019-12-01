# include<iostream>
# include<algorithm>
# include<cstdio>
# include<cmath>

# define maxsize 22

using namespace std;

int num[maxsize][maxsize];

typedef struct Node{
	int x;
	int y;
	int weight;
}Node;

void Sum(Node *&node,int &count,const int &N,const int &M,const int &i,const int &j){
	int sum=0;
	if(i>0){//上面 
		if(num[i][j]*num[i-1][j]<0){
			sum=sum+abs(num[i-1][j]);
		}
		else{
			sum=sum-abs(num[i-1][j]);
		}
	}
	if(j>0){//左边 
		if(num[i][j]*num[i][j-1]<0){
			sum=sum+abs(num[i][j-1]);
		}
		else{
			sum=sum-abs(num[i][j-1]);
		}
	}
	if(i<N-1){//下面 
		if(num[i][j]*num[i+1][j]<0){
			sum=sum+abs(num[i+1][j]);
		}
		else{
			sum=sum-abs(num[i+1][j]);
		}
	}
	if(j<M-1){//右边 
		if(num[i][j]*num[i][j+1]<0){
			sum=sum+abs(num[i][j+1]);
		}
		else{
			sum=sum-abs(num[i][j+1]);
		}
	} 
	node[count].x=i;
	node[count].y=j;
	node[count].weight=sum;
	count++;
}

void Handle(Node *&node,const int &N,const int &M){
	int i,j,count=0;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++)
		Sum(node,count,N,M,i,j);
	}
}

bool cmp(const Node &a,const Node &b){
	if(a.weight>b.weight)
	return 1;
	else if(a.weight==b.weight){
		if(a.x<b.x)
		return 1;
		else if(a.x==b.x&&a.y<b.y)
		return 1;
		else
		return 0;
	}
	else
	return 0;
}

int main(void){
	int N,M,i,j,len;
	while(cin>>N>>M){
		if(N==0&&M==0)
		break;
		Node *node=new Node[N*M];
		len=N*M;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++)
			cin>>num[i][j];
		}
		Handle(node,N,M);
		sort(node,node+len,cmp);
		cout<<node[0].x+1<<" "<<node[0].y+1<<" "<<node[0].weight<<endl;	
		delete [] node;
	}
	return 0;
}
