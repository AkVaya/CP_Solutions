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
#define eb emplace_back
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
    ll c,d,x,y,z,n,k,t;
    cin>>t;
    while(t--){
        cin>>n;
        ll a[n],ans=0,count[n],ind=-1;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        if(a[n-1]%2)
            count[n-1]=1;
        else{
            ind=n-1;
            if(a[n-1]%4==0)
                count[n-1]=1;
            else
                count[n-1]=0;
        }
        ans+=count[n-1];
        for (int i = n-2; i >= 0; --i)
        {
            if(a[i]%2 && a[i+1]%4==0)
                count[i]=1+count[i+1];
            else if(a[i]%2)
                count[i]=1+count[i+1];
            else if(a[i]%4==0){
                ind=i;
                count[i]=n-i;
            }
            else{
                if(ind==-1)
                    count[i]=0;
                else
                    count[i]=n-ind;
                ind=i;
            }
            ans+=count[i];
            //cout<<count[i]<<" ";
        }
        cout<<ans<<endl;
    }
    return 0 ;
}
