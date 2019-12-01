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
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

char str[maxn];
int len;
int num[30];

bool check(){
	for(int i=0;i<26;i++){
		if(!num[i])
			return 0;
	}
	return 1;
}

void handle(int l,int r){
	memset(num,0,sizeof(num));
	for(int i=l;i<=r;i++){
		num[str[i]-'A']++;
	}
}

int main(void){
	int ans,pos;
	while(scanf("%s",str+1)!=EOF){
		len=strlen(str+1);
		pos=len+1;
		memset(num,0,sizeof(num));
		for(int i=1;i<=len;i++){
			num[str[i]-'A']++;
			if(check()){
				pos=min(pos,i);
			}
		}
		if(!check()){
			puts("No Solution");
			continue;
		}
		ans=pos;
		int l=1,r=pos;
		handle(l,r);
		while(r<=len){
			//deb(l);
			//deb(r);
			if(check()){
				ans=min(ans,r-l+1);
				num[str[l]-'A']--;
				l++;
				continue;
			}
			r++;
			if(r>len)
				break;
			num[str[r]-'A']++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
