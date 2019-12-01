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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxn=1e7+10;

int n,nc,cnt;
char s[maxn];
int num[310];
int s_len,len;
int mp[maxn];
int ans;

int main(void){
	int tmp,res;
	while(scanf("%d %d",&n,&nc)!=EOF){
		scanf("%s",s);
		cnt=0;
		memset(num,0,sizeof(num));
		memset(mp,0,sizeof(mp));
		s_len=strlen(s);
		for(int i=0;i<s_len;i++){
			if(!num[s[i]]){
				num[s[i]]=cnt++;
			}
		}
		ans=0;
		for(int i=0;i<s_len-n+1;i++){
			tmp=1;
			res=0;
			for(int j=i;j<i+n;j++){
				res+=num[s[j]]*tmp;
				tmp*=nc;
			}
			if(!mp[res]){
				mp[res]=1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
