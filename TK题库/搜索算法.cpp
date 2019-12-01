# include<stdio.h>

# define Maxsize 22

char map[Maxsize][Maxsize];
int isvisited[Maxsize][Maxsize];
int count; 

void Go(int W,int H,int x,int y){
	if(x>0&&map[x-1][y]=='.'&&!isvisited[x-1][y]) {//向上走 
		isvisited[x-1][y]=1;
		count++;
		Go(W,H,x-1,y);
	}
	if(x<H-1&&map[x+1][y]=='.'&&!isvisited[x+1][y]){//向下走 
		isvisited[x+1][y]=1;
		count++;
		Go(W,H,x+1,y);
	}
	if(y>0&&map[x][y-1]=='.'&&!isvisited[x][y-1]){//向左走 
		isvisited[x][y-1]=1;
		count++;
		Go(W,H,x,y-1);
	}
	if(y<W-1&&map[x][y+1]=='.'&&!isvisited[x][y+1]){//向右走 
		isvisited[x][y+1]=1;
		count++;
		Go(W,H,x,y+1);
	}
}

int main(void){
	int W,H,i,j,x,y;
	while(scanf("%d %d",&W,&H)){
		if(W==0&&H==0)
		break;
		for(i=0;i<H;i++){
		getchar();
		for(j=0;j<W;j++){
			scanf("%c",&map[i][j]);
			isvisited[i][j]=0;
			if(map[i][j]=='@'){//记录小明的位置 
				x=i;
				y=j;
			}
		}
	}
	isvisited[x][y]=1;
	count=1;
	Go(W,H,x,y);
	printf("%d\n",count);
	}
	return 0;
}
