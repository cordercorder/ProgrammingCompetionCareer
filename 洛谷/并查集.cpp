# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>

using namespace std;

const int maxsize=1e4+5;

int n,m;
int parent[maxsize];

int Find(int x){
	return x==parent[x]? x:parent[x]=Find(parent[x]);//Â·¾¶Ñ¹Ëõ 
}

void Union(const int &x,const int &y){
	int nx=Find(x),ny=Find(y);
	if(nx!=ny) 
		parent[ny]=nx;
}

int main(void){
	int i;
	int x,y,z;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		parent[i]=i;
	while(m--){
		scanf("%d %d %d",&z,&x,&y);
		if(z==2){
			if(Find(x)==Find(y)){
				printf("Y\n");
			}
			else{
				printf("N\n");
			}
		} 
		else if(z==1){
			Union(x,y);
		}
	}
	return 0;
}
