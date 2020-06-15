#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#include<ctime>
#include<cmath>
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+1;
void solve(){
    ll n;
    cin>>n;
    ll mx=0,temp=n,dig=0,a[6]={0,0,0,0,0,0};
    while(temp>0){
        mx=max(mx,temp%10);
        a[dig]=temp%10;
        temp/=10;
        dig++;
    }
    string s[mx];
    for (int i = 0; i < dig; ++i)
    {
        for (int j = 0; j < mx; ++j)
        {
            if(a[i]>0){
                s[j]+="1";
                a[i]--;
            }
            else
                s[j]+="0";
        }
    }
    cout<<mx<<endl;
    for (int i = 0; i < mx; ++i)
    {
        reverse(s[i].begin(), s[i].end());
        bool check=false;
        ll ind=0;
        if(s[i][ind]=='0'){
            while(s[i][ind]=='0')
                ind++;
        }
        for (int j = ind; j < s[i].size(); ++j)
        {
            cout<<s[i][j];
        }
        cout<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}