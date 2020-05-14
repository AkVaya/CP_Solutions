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
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 10000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1,s2,s="";
    cin>>s1>>s2;
    ll dp[s1.length()+1][s2.length()+1]={0};
    for (int i = 0; i <=s1.length(); ++i)
    {
        for (int j = 0; j <= s2.length(); ++j)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    ll i=s1.length(),j=s2.length();
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s+=s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1])
            i--;
        else
            j--;
    }
    for (int i = s.length()-1; i >=0; --i)
    {
        cout<<s[i];
    }
    return 0 ;
}
