#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<math.h>
#include<string.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
#define inf 1000000000000000000
using namespace std;
void solve(){
    int m,n;
    string s1,s2;
    cin>>s1;
    for (int i = 0; i < s1.length(); ++i)
    {
    	s2+=s1[s1.length()-i-1];
    }
    m=s1.length();n=s2.length();
    int ans[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                ans[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                ans[i][j]=1+ans[i-1][j-1];
            }
            else{
                ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
            }
        }
    }
    cout<<s1.length()-ans[m][n]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){        
        solve();
    }
    return 0 ;
}