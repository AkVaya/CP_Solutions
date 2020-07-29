#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<iomanip>
#include<queue>
#include<bitset>
#define endl '\n'
#define Fi first
#define Se second
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =998244353;
const ll nax=100000000;
const ll inf=1e18;
using pii = pair<ll,ll>;
const ll MAX = 86044176;
const ll LMT = 9267;
const ll LEN = 5000000;
unsigned int flag[MAX>>6], primes[LEN+5];
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
void sieve()
{
	ll i,j,k;
	for(i = 3; i < LMT; i+=2)
    {
        if(!ifc(i))
        {
            for(j=i*i, k=i<<1; j < MAX; j+=k)
                isc(j);
        }
    }
    primes[1] = 2;
    for(i=3, j=2; i < MAX && j <= LEN; i+=2)
        if(!ifc(i))
            primes[j++] = i;
}
void solve(){

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

    ll t=1,t1=1;
    sieve();
    cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";   
		ll x;
		cin>>x;
		cout<<primes[x]<<endl;
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}