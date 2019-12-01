#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

/*head------[@cordercorder]*/

const int maxn=(int)1e5+10; 

char s[maxn];
int len;
int ret[maxn*4],res[10],ans[maxn*100],ans_tmp[maxn*100],tmp[maxn*4];
int lenret,lenres;

int cal(char ch){
    if(ch>='0'&&ch<='9'){
        return (int)(ch-'0');
    }
    else{
        return (int)(ch-'A')+10;
    }
}

void mul(){
    for(int i=1;i<=lenret;i++){
        for(int j=1;j<=lenres;j++){
            ans_tmp[i+j-1]=ret[i]*res[j];
        }
    }
    int pos=lenret+lenres+5;
    for(int i=1;i<=pos;i++){
        ans_tmp[i+1]+=ans_tmp[i]/10;
        ans_tmp[i]%=10;
    }
    
    
}

void solve(){
    len=strlen(s+1);
    ret[1]=1;
    lenret=1;
    int num;
    for(int i=len;i>=1;i--){
        num=cal(s[i]);
        lenres=0;
        if(num>=10){
            res[++lenres]=num%10;
            res[++lenres]=num/10;
        }
        else{
            res[++lenres]=num%10;
        }
        mul();
        res[1]=6;
        res[2]=3;
        for(int j=1;j<=lenret;j++){
            for(int k=1;k<=2;k++){
                tmp[j+k-1]=ret[j]*res[k];
            }
        }
        for(int j=1;j<=lenret+5;j++){
            tmp[j+1]+=tmp[j]/10;
            tmp[j]%=10;
            tmp[j]=0;
        }
        int j;
        for(j=1;tmp[j]!=0;j++){
            ret[j]=tmp[j]; 
        }
        lenret=j-1;
    }
    
}

int main(void){
    scanf("%s",s+1);
    
    
    
    return 0;
}
