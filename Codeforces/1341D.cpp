#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<bitset>
#include<vector>
#include<iomanip>
#include<queue>
#include<unordered_set>
//#define endl '\n'
#define Fir first
#define Sec second
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
#define LB lower_bound
#define UB upper_bound
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-base)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e3+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
char a[nax][nax];
void solve(){ 
    ll n,k;
    cin>>n>>k;
    map<ll,string> m;
    m[0]="1110111";
    m[1]="0010010";
    m[2]="1011101";
    m[3]="1011011";
    m[4]="0111010";
    m[5]="1101011";
    m[6]="1101111";
    m[7]="1010010";
    m[8]="1111111";
    m[9]="1111011";
    string s[n];
    vector<vector<ll> > diff(n,vector<ll>(10));
    for( int i = 0; i < n; ++i){
        cin>>s[i];
        for( int digit = 0; digit < 10; ++digit){
            for( int x = 0; x < 7; ++x){
                char curr=s[i][x];
                char target=m[digit][x];
                if(curr=='1' && target=='0'){
                    diff[i][digit]=-1;
                    break;
                }
                if( curr=='0' && target=='1')
                    diff[i][digit]++;
            }
        }
    }
    vector<vector<ll> >dp(n+1,vector<ll>(k+1,0));
    dp[n][0]=1;
    for( int i = n; i > 0; --i){
        for( int j = 0; j <= k; ++j){
            if(dp[i][j]){
                for( int x = 0; x < 10; ++x){
                    if(diff[i-1][x]!=-1 && j+diff[i-1][x]<=k){
                        dp[i-1][j+diff[i-1][x]]=1;
                    }
                }
            }
        }
    }
    //cout<<"DP"<<endl;
    if(dp[0][k]==0){
        cout<<-1<<endl;
        return;
    }
    //cout<<"YAHA"<<endl;
    for( int i = 0; i < n; ++i ){
        ll curr=-1;
        for( int digit = 9; digit >= 0; --digit){
            if(diff[i][digit]!=-1 && diff[i][digit]<=k && dp[i+1][k-diff[i][digit]]>0){
                curr=digit;
                k-=diff[i][digit];
                break;
            }
        }
        if(curr==-1){
            cout<<-1<<endl;
            return;
        }
        cout<<curr;
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

    //clock_t t3 = clock();
    ll t=1,t1=1;
    //cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}