#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
#include<string.h>
#define ll  long long
using namespace std;
string s1="";
string decToBinary(ll n) 
{ 
    string s="";
    int binaryNum[64]; 
    int i = 0; 
    while (n > 0) {  
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    for (int j = i - 1; j >= 0; j--) 
        s+=to_string(binaryNum[j]);
    return s;
} 
vector<bool> x(150000000,false);
void simpleSieve(ll limit, vector<ll> &prime) 
{ 
    bool mark[limit+1]; 
    memset(mark, true, sizeof(mark));   
    for (ll p=2; p*p<limit; p++) 
    { 
        if (mark[p] == true) 
        { 
            s1+=decToBinary(p);
            for (ll i=p*2; i<limit; i+=p) 
                mark[i] = false; 
        } 
    }  
    for (ll p=2; p<limit; p++) 
    { 
        if (mark[p] == true) 
        { 
            prime.push_back(p); 
            x[p]=true;
        } 
    } 
} 
void segmentedSieve(ll n) 
{  
    ll limit = floor(sqrt(n))+1;
    vector<ll> prime; 
    simpleSieve(limit, prime);   
    ll low = limit; 
    ll high = 2*limit;  
    while (low < n) 
    { 
        if (high >= n)  
           high = n; 
        bool mark[limit+1]; 
        memset(mark, true, sizeof(mark));  
        for (ll i = 0; i < prime.size(); i++) 
        { 
            ll loLim = floor(low/prime[i]) * prime[i]; 
            if (loLim < low) 
                loLim += prime[i]; 
            for (ll j=loLim; j<high; j+=prime[i]) 
                mark[j-low] = false; 
        }  
        for (ll i = low; i<high; i++) 
            if (mark[i - low] == true){
                x[i]=true;
                s1+=decToBinary(i);
            }
        low = low + limit; 
        high = high + limit; 
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n , k ,ans=0;
    cin>>n>>k;
    segmentedSieve(150000000);
    cout<<s1.size()<<endl;
    return 0;
}