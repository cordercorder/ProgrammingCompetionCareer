# include<iostream>
# include<algorithm>
# include<cstdio>
# include<cmath>

using namespace std;

const int maxsize=405;

typedef struct node{
	int x;
	int y;
	int val;
}node;

node data[maxsize];

int M,N,k;

bool cmp(const node &a,const node &b){
	return a.val>b.val;
}

bool check(const int &nx,int &tim,int &res){
	//cout<<"time="<<tim<<endl;
	int temp=tim,back;
	if(nx==0){
		temp=data[nx].x+2+temp;//采摘花生消耗的时间 
		back=data[nx].x+1+temp;//判断是否能回去 
		if(back<=k){
			tim=temp;
			res=data[nx].val+res;
			return 1;
		}
		else
			return 0;
	}
	temp=abs(data[nx].x-data[nx-1].x)+abs(data[nx].y-data[nx-1].y)+1+temp;////采摘花生消耗的时间 
	//cout<<"1temp="<<temp<<endl;
	back=data[nx].x+temp+1;//判断是否能回去 
	if(back>k)
		return 0;
	tim=temp;
	res=data[nx].val+res;
	return 1;
}

int main(void){
	int i,j,v,count=0,tim,res;
	cin>>M>>N>>k;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			cin>>v;
			if(v){
				data[count].x=i;
				data[count].y=j;
				data[count++].val=v;
			}
		}
	}
	sort(data,data+count,cmp);
	tim=0;
	res=0;
	for(i=0;i<count;i++){
		//cout<<data[i].x<<" "<<data[i].y<<" "<<data[i].val<<endl;
		if(!check(i,tim,res)){
			break;
		}
	}
	cout<<res<<endl;
	return 0;
}
