#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e6+5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll n,k;
    cin>>n;
    map<string,set<string> > m;
    string name,temp;
    for (int i = 0; i < n; ++i)
    {
        cin>>name;
        cin>>k;
        for (int x = 0; x < k; ++x)
        {
            cin>>temp;
            m[name].ins(temp);
        }
    }
    for(auto i : m){
        for(auto j : i.second){
            for(auto k : i.second){
                if(j==k)
                    continue;
                if(j.length()>=k.length() && j.substr(j.length()-k.length(),k.length())==k)
                    m[i.first].erase(k);
                if(k.length()>j.length() && k.substr(k.length()-j.length(),j.length())==j)
                    m[i.first].erase(j);
                /*if(j.length()>=k.length()){  
                    cout<<j<<" "<<k<<" : ";
                    cout<<j.substr(j.length()-k.length(),k.length())<<endl;
                }
                else{
                    cout<<j<<" "<<k<<" : "<<k.substr(k.length()-j.length(),j.length())<<endl;
                }*/

            }
        }
    }
    ll cnt=0;
    for(auto i : m){
        if(i.second.size())
            cnt++;
    }
    cout<<cnt<<endl;
    for(auto i : m){
        if(i.second.size()){
            cout<<i.first<<" ";
            cout<<i.second.size()<<" ";
            for (auto j : i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
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