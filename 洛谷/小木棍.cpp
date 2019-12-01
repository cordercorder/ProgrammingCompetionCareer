# include<iostream>
# include<algorithm>
# include<cstdio>
# include<vector> 

using namespace std;

vector<int> a;

int main(void){
	int N,i,temp;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&temp);
		if(temp<=50)
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	printf("%d\n",a.back()+a.front());
	return 0;
}
