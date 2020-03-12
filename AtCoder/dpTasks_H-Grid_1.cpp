#include<iostream>
#define ll long long
using namespace std;
ll M=1e9 +7;
int main(){
    ll h,w;
    cin>>h>>w;
    char a[h][w];
    ll dp[h][w]={0};
    for (ll i = 0; i < h; ++i)
    {
        for (ll j = 0; j < w; ++j)
        {
            cin>>a[i][j];
            if(a[i][j]=='#')    dp[i][j]=-1;
            else dp[i][j]=0;
        }
    }
    dp[0][0]={0};
    bool check=false;
    for (int i = 1; i <w; ++i)
    {
        if(dp[0][i]==-1 && !check){
            check=true;
        }
        else if(check){
            dp[0][i]=-1;
        }
        else 
            dp[0][i]=1;
    }
    check=false;
    for (int i = 1; i <h; ++i)
    {
        if(dp[i][0]==-1 && !check){
            check=true;
        }
        else if(check){
            dp[i][0]=-1;
        }
        else 
            dp[i][0]=1;
    }
    for (ll i = 1; i <h; ++i)
    {
        for (ll j = 1; j <w ; ++j)
        {
            if(dp[i][j]==-1)
                continue;
            if( dp[i-1][j]>0 )
                dp[i][j]=((dp[i-1][j])+dp[i][j]+M)%M;
            if( dp[i][j-1]>0)
                dp[i][j]=((dp[i][j])+dp[i][j-1]+M)%M;
        }
    }
   /* for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[h-1][w-1];

    return 0;
}