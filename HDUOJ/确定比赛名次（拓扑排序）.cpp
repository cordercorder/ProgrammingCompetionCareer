# include<iostream>
# include<algorithm>
# include<cstring>
# include<queue>

using namespace std;

const int maxsize=5e2+10;

int n,m,cnt;
int in[maxsize];
bool map[maxsize][maxsize];
int output[maxsize];
priority_queue<int,vector<int>,greater<int> >q;

void TopSort(){//�������� 
	int i,tmp;
	cnt=0;
	for(i=1;i<=n;i++){
		if(in[i]==0)
			q.push(i);//���Ϊ0�ĵ���� 
	}
	while(!q.empty()){
		tmp=q.top();
		output[cnt++]=tmp;
		q.pop();
		for(i=1;i<=n;i++){
			if(map[tmp][i]){
				in[i]--;//�����Ϊ0�Ľڵ㷢��������߶�ɾ��
				if(in[i]==0){
					q.push(i);
				}
			}
		}
	}
	if(cnt!=n)
		return ;//�л���ͼ 
	for(i=0;i<cnt;i++){
		if(i){
			printf(" %d",output[i]);
			continue;
		}
		printf("%d",output[i]);
	}
	printf("\n");
}

int main(void){
	int a,b,i;
	while(scanf("%d %d",&n,&m)!=EOF){//n����m���� 
		memset(in,0,sizeof(in));
		memset(map,0,sizeof(map));
		for(i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			if(!map[a][b]){
				map[a][b]=1;
				in[b]++;
			}
		}
		TopSort();
	}
	return 0;
}
