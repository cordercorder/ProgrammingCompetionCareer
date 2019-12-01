# include<iostream>
# include<cmath>
# include<cstring>

using namespace std;

typedef struct node{
	double x;
	double y;
}node;

int *parent;
int *op;

int Find(int x){
	while(parent[x]!=x){
		x=parent[x];
	}
	return x;
}

bool check(const int &nx,const int &ny){
	int x=Find(nx),y=Find(ny);
	if(x==y)
	return 1;
	else
	return 0;
}

bool Union(const int &x,const int &y){
	int nx=Find(x),ny=Find(y);
	if(nx==ny)
	return 1;
	parent[nx]=ny;
	return 0;
}

double len(const node &a,const node &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
} 

int main(void){
	int N,d,i,nx,ny,count=0;
	char ch;
	cin>>N>>d;
	node *num=new node[N+1];
	parent=new int[N+1];
	op=new int[N];
	memset(op,0,sizeof(int)*N);
	for(i=1;i<=N;i++){
		cin>>num[i].x>>num[i].y;
		parent[i]=i;
	}
	while(cin>>ch){
		if(ch=='O'){
			cin>>nx;
			for(i=0;i<count;i++){
				if(len(num[op[i]],num[nx])<=d){
					Union(op[i],nx);
				}
			}
			op[count++]=nx;
			//cout<<"count="<<count<<endl;
		}
		else if(ch=='S'){
			cin>>nx>>ny;
			if(check(nx,ny))
			cout<<"SUCCESS"<<endl;
			else
			cout<<"FAIL"<<endl;
		}
	}
	return 0;
}
