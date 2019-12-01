#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

/*head------[@cordercorder]*/

const int maxn=1010;

int T;

char s[maxn];
int inputbase,outputbase;
int num[maxn],ans[maxn];

void solve(){
    int len=strlen(s),cnt=0,tot=0;
    for(int i=len-1;i>=0;i--){
        if(s[i]>='0'&&s[i]<='9'){
            num[cnt++]=(int)(s[i]-'0');
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            num[cnt++]=(int)(s[i]-'A'+10);
        }
        else if(s[i]>='a'&&s[i]<='z'){
            num[cnt++]=(int)(s[i]-'a'+36);
        }
    }
    while(len>0){
        for(int i=len-1;i>0;i--){
            num[i-1]+=num[i]%outputbase*inputbase;
            num[i]/=outputbase;
        }
        ans[tot++]=num[0]%outputbase;
        num[0]/=outputbase;
        while(len>0&&num[len-1]==0){
            len--;
        }
    }
    printf("%d ",outputbase);
    char ch;
    for(int i=tot-1;i>=0;i--){
        if(ans[i]>=0&&ans[i]<=9){
            ch=(char)(ans[i]+'0');
        }
        else if(ans[i]>=10&&ans[i]<=35){
            ch=(char)(ans[i]-10+'A');
        }
        else if(ans[i]>=36&&ans[i]<=61){
            ch=(char)(ans[i]-36+'a');
        }
        printf("%c",ch);
    }
    printf("\n\n");
}

int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %s",&inputbase,&outputbase,s);
        printf("%d %s\n",inputbase,s);
        solve();
    }
    return 0;
}
