# include<iostream>
# include<string>
 
using namespace std;
 
 
 
int main()
{
    int t;
    cin>>t;
 
    int n;
    string a;
 
    int record;
 
 
 
    while(t--)
    {
        string c="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        cin>>n>>a;
        char MIN='z';
        int l=a.length();
        for(int i=0; i<l; i++)
        {
            MIN=min(MIN,a[i]);
        }
        for(int i=0; i<l; i++)
        {
            if(a[i]==MIN)
            {
                string b=a.substr(i,n)+a.substr(0,i);
 
                if(c>b)
                {
                    c=b;
                    record=i;
                }
            }
        }
        cout<<record<<endl;
    }
    return 0;
}
