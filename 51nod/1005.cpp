#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define deb(x) cerr<<#x<<"------>"<<x<<endl

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

typedef long long ll;
typedef unsigned long long ull;

/*head------[@cordercorder]*/

const int maxn=(int)1e4+10;

char A[maxn],B[maxn];
int numa[maxn],numb[maxn],ans[maxn];
int lena,lenb;

void handle(char *s,int *num,int len){
    int i=0;
    if(s[0]=='-'){
        for(i=0;i+1<len;i++){
            num[i]=(int)(s[len-i-1]-'0');
        }
    }
    else{
        for(i=0;i<len;i++){
            num[i]=(int)(s[len-i-1]-'0');
        }
    }
}

void Add(){
    int len=max(lena,lenb),tmp;
    for(int i=0;i<len;i++){
        ans[i]=numa[i]+numb[i];
    }
    for(int i=0;i<len;i++){
        tmp=ans[i];
        ans[i]=tmp%10;
        ans[i+1]+=tmp/10;
    }
}

void Sub(int *numx,int *numy){
    int len=max(lena,lenb);
    for(int i=0;i<len;i++){
        ans[i]=numx[i]-numy[i];
    }
    for(int i=0;i<len;i++){
        if(ans[i]<0){
            ans[i]+=10;
            ans[i+1]--;
        }
    }
}

void Show(bool f=false){
    if(f){
        printf("-");
    }
    int len=max(lena,lenb);
    int pos=len+1;
    while(pos>0&&ans[pos]==0){
        pos--;
    }
    for(int i=pos;i>=0;i--){
        printf("%d",ans[i]);
    }
}

void solve(){
    lena=strlen(A);
    lenb=strlen(B);
    handle(A,numa,lena);
    handle(B,numb,lenb);
    if((A[0]=='-'&&B[0]=='-')||(A[0]!='-'&&B[0]!='-')){
        Add();
        if(A[0]=='-'&&B[0]=='-')
            Show(true);
        else{
            Show();
        }
    }
    else{
        if(B[0]=='-'){
            swap(A,B);
            swap(numa,numb);
            swap(lena,lenb);
        }
        if(lena-1>lenb){
            Sub(numa,numb);
            printf("-");
            Show();
        }
        else if(lena-1==lenb){
            bool f=false;
            for(int i=1,j=0;j<lenb;i++,j++){
                if(A[i]>B[j]){
                    f=true;
                    break;
                }
                else if(A[i]<B[j]){
                    f=false;
                    break;
                }
            }
            if(f){
                Sub(numa,numb);
                Show(true);
            }
            else{
                Sub(numb,numa);
                Show();
            }
        }
        else{
            Sub(numb,numa);
            Show();
        }
    }
}

int main(void){
    scanf("%s %s",A,B);
    solve();
    return 0;
}
