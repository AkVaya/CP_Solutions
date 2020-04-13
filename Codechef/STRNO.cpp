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
#define M 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*vector<bool> v(1000001);
    fill(v.begin(),v.end(),true);
    vector<ll> x;
    v[0]=false;
    v[1]=false;
    x.emplace_back(2);
    for (ll i = 3; i <=1000000; i+=2)
    {
        if (v[i]==true)
        {
            x.emplace_back(i);
            for (ll j = i*i; j <= 1000000; j+=i)
            {
                v[j]=false;
            }
        }
    }*/
    ll t;
    cin>>t;
    while(t--){
        ll n,k,x;
        cin>>n>>k;
        ll count=0;
        if(n%2==0){
            while(n%2==0){
                n/=2;
                count++;
            }
        }
        x=n;
        for (int i = 3; i <= sqrt(x); i+=2)
        {
            if(n%i==0){
               // count++;
                while(n%i==0){
                    count++;
                    n/=i;
                }
            }
            if(n==1)
                break;
        }
        if(n!=1)
            count++;
       // cout<<count<<" ";
        if(count>=k)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
} 