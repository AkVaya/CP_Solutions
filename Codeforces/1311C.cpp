#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define ins insert 
#define mp make_pair
#define fi first
#define se second
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 1000000000000
using namespace std;
int main(){
    ll t,n,m,x;
    cin>>t;
    while(t--){
        cin>>n>>m;
        char s[n];
        ll initial[n][26]={0};
        ll b[m];
        for (int i = 0; i < n; ++i)
        {
            cin>>s[i];
            initial[i][s[i]-'a']++;
            if(i>0){
                for(int j=0;j<26 ;j++){
                    initial[i][j]+=initial[i-1][j];
                 //   cout<<initial[i][j]<<" ";
                }
               // cout<<endl;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            cin>>b[i];
        }
        ll a[26]={0};
        for (int i = 0; i < 26; ++i)
        {
            a[i]+=initial[n-1][i];
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                a[j]+=initial[b[i]-1][j];
            }
        }
        for (int i = 0; i < 26; ++i)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}