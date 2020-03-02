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
vector<ll> primes;
void simpleSieve(ll limit) 
{ 
    bool mark[limit+1]; 
    memset(mark, true, sizeof(mark)); 
    for (int p=2; p*p<limit; p++) 
    { 
        if (mark[p] == true) 
        { 
            for (int i=p*2; i<limit; i+=p) 
                mark[i] = false; 
        } 
    } 
    for (int p=2; p<limit; p++) 
    { 
        if (mark[p] == true) 
        { 
            primes.push_back(p); 
            //cout << p << " "; 
        } 
    } 
} 
void segmentedSieve(int n) 
{ 
    ll limit = floor(sqrt(n))+1; 
  
    simpleSieve(limit);  
    ll low = limit; 
    ll high = 2*limit; 
    while (low < n) 
    { 
        if (high >= n)  
           high = n; 

        bool mark[limit+1]; 
        memset(mark, true, sizeof(mark)); 
        for (ll i = 0; i < primes.size(); i++) 
        { 

            ll loLim = (low/primes[i]) * primes[i]; 
            if (loLim < low) 
                loLim += primes[i]; 

            for (ll j=loLim; j<high; j+=primes[i]) 
                mark[j-low] = false; 
        }  
        for (ll i = low; i<high; i++) 
            if (mark[i - low] == true) 
                primes.pb(i); 
        low = low + limit; 
        high = high + limit; 
    } 
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    segmentedSieve(3000000);
    vector<ll> v;
    for (int i = 0; i < 30000; ++i)
    {
        for (int j = i+1; j < 30000; ++j)
        {
 //       	if((primes[i]*primes[j])>10527449)
    //    		break;
            v.pb(primes[i]*primes[j]);
        }
    }
    sort(v.begin(), v.end());
    ll t,a;
    cin>>t;
    while(t--){
        cin>>a;
        cout<<v[a-1]<<endl;
    }
    return 0 ;
}