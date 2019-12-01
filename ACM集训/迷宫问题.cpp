# include<iostream>
# include<stack>

using namespace std;

const int maxsize=6;
const int maxsize2=100;

int map[maxsize][maxsize];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1}; 

typedef struct node{
	int x;
	int y;
}node;

node num={0,0};

stack<node> S;

void Go(){
	int i,nx,ny,flag;
	while(nx!=4||ny!=4){
		flag=0;
		for(i=0;i<4;i++){
		nx=S.top().x+dx[i];
		ny=S.top().y+dy[i];
		if(nx<5&&nx>=0&&ny<5&&ny>=0&&map[nx][ny]==0){
			num.x=nx;
			num.y=ny;
			map[nx][ny]=2;
			S.push(num);
			//cout<<"nx="<<nx<<" ny="<<ny<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0){
		map[S.top().x][S.top().y]=-1;
		S.pop();
	}
	}
}

int main(void){
	int i,j,count=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++)
		scanf("%d",&map[i][j]);
	}
	map[0][0]=2;
	S.push(num);
	Go();
	node *data=new node[maxsize2];
	while(!S.empty()){
	//	cout<<S.top().x<<","<<S.top().y<<endl;
		data[count].x=S.top().x;
		data[count++].y=S.top().y;
		S.pop();
	}
	for(i=count-1;i>=0;i--)
	cout<<"("<<data[i].x<<", "<<data[i].y<<")"<<endl;
	return 0;
}
