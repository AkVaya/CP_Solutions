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
#define M 1000000000
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,k,ans,x,count;
    string s;
    cin>>t;
    while(t--){
        cin>>s>>k;
        ll a[26]={0};
        for(int i=0;i<s.length();i++){
            a[s[i]-'a']++;
        }
        ans=M;
        for(int i=0;i<26;i++)
        {
            if(a[i] > 0)
            {
                x=a[i],count=0;
                for(int j=0;j<26;j++)
                {
                    if(a[j] < x){
                        count+=a[j];
                    }
                    else if(a[j] > x+k){
                        count+=a[j]-x-k;
                    }
                }
                ans=min(ans,count);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}