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
#define M 10000007
using namespace std;
int editDistance(string s1, string s2) {  
    int m = s1.size();  
    int n = s2.size();  
    int dp[m + 1][n + 1];  
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {  
        dp[0][i] = i;  
    }    
    for (int i = 1; i <= m; i++) {  
        dp[i][0] = i;  
    }  
    for (int i = 1; i <= m; i++) {  
        for (int j = 1; j <= n; j++) {  
            if (s1[i - 1] == s2[j - 1]) {  
                dp[i][j] = dp[i - 1][j - 1]; 
            }  
            else {  
                dp[i][j] = 1 + min3(dp[i - 1][j - 1],dp[i][j - 1],dp[i - 1][j]);      
            }  
        }  
    }  
    return dp[m][n];  
}
int main()
{
    ll t;
    string s1,s2;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        cout<<editDistance(s2,s1)<<endl;
    }

        
    return 0;
} 