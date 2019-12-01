# include<iostream>
# include<cstring>

using namespace std;

const int maxsize=10;

char num[maxsize][maxsize];
int sum,n,k,op;
bool isvisited[maxsize];

void dfs(int x){
	int i;
	if(op==k){
		sum++;
		return ;
	}
	if(x>=n)
	return ;
	for(i=0;i<n;i++){
		if(!isvisited[i]&&num[x][i]=='#'){
			isvisited[i]=1;
			op++;
			dfs(x+1);
			isvisited[i]=0;
			op--;
		}
	}
	dfs(x+1);
}

int main(void){
	int i,j;
	char ch;
	while(cin>>n>>k){
		if(n==-1&&k==-1)
		break;
		sum=0;
		op=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>num[i][j];
			}
		}
		memset(isvisited,0,sizeof(bool)*maxsize);
		dfs(0);
		cout<<sum<<endl;
	}
	return 0;
}
