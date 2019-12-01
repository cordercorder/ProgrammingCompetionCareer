# include<iostream>
# include<queue>
# include<cstring>

using namespace std;

const int maxsize=200001;

typedef struct node{
	int len;
	int steps;
}node;

int isvisited[maxsize];

bool check(const int &m){
	if(m<0||m>maxsize||isvisited[m])
		return 0;
	return 1;
}

int bfs(const int &N,const int &K){
	queue<node> Q;
	node temp,num;
	num.len=N;
	num.steps=0;
	isvisited[N]=0;
	Q.push(num);
	while(!Q.empty()){
		num=Q.front();
		Q.pop();
		if(num.len==K)
			return num.steps;
		temp.len=num.len*2;
		temp.steps=num.steps;
		if(check(temp.len)){
			temp.steps=temp.steps+1;
			isvisited[temp.len]=1;
			Q.push(temp);
		}
		temp.len=num.len+1;
		temp.steps=num.steps;
		if(check(temp.len)){
			temp.steps=temp.steps+1;
			isvisited[temp.len]=1;
			Q.push(temp);
		}
		temp.len=num.len-1;
		temp.steps=num.steps;
		if(check(temp.len)){
			temp.steps=temp.steps+1;
			isvisited[temp.len]=1;
			Q.push(temp);
		}
	}
}

int main(void){
	int N,K;
	while(cin>>N>>K){
		memset(isvisited,0,sizeof(int)*maxsize);
		cout<<bfs(N,K)<<endl;
	}
	return 0;
}
