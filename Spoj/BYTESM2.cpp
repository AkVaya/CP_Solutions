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
ll a[100][100],dp[100][100];
ll h,w;
ll fun(int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        if(j>=1 && j<w-1){
            dp[i][j] = a[i][j]+ max3(fun(i+1,j+1),fun(i+1,j-1),fun(i+1,j));
        }
        else if(j==0){
            dp[i][j] = a[i][j]+ max(fun(i+1,j),fun(i+1,j+1));
        }
        else if(j==w-1){
            dp[i][j] = a[i][j]+ max(fun(i+1,j),fun(i+1,j-1));
        }
        return dp[i][j];

    }
}
int main()
{
    ll t,n,x,ans;
    cin>>t;
    while(t--){
        cin>>h>>w;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin>>a[i][j];
                if(i<h-1)
                    dp[i][j]=-1;
                else
                    dp[i][j]=a[i][j];
            }
        }
        ans=0;
        for (int j = 0; j < w; ++j)
        {
            x=fun(0,j);
            if(ans<x){
                ans=x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
} 