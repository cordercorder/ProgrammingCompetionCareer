# include<iostream>
# include<algorithm>
# include<cstring>

using namespace std;

const int maxsize=1005;

int M,N;
int Q[maxsize];
int front,rear;
int temp[maxsize];

void solve(int *&num){
	int i,ans=0;
	front=rear=0;
	memset(temp,0,sizeof(int)*maxsize);
	for(i=0;i<N;i++){
		if(front-rear<M&&!temp[num[i]]){
			temp[num[i]]++;
			Q[front++]=num[i];//入队 
			ans++;
		}
		else if(!temp[num[i]]&&front-rear==M){
			temp[Q[rear]]--;//队尾元素出队 
			rear++;//出队 
			Q[front++]=num[i];//新元素入队 
			temp[num[i]]++;//记录新元素出现的次数 
			ans++;
		}
	}
	cout<<ans<<endl;
}

int main(void){
	int i;
	cin>>M>>N;
	int *num=new int[N];
	for(i=0;i<N;i++)
		cin>>num[i];
	solve(num);
	return 0;
}
