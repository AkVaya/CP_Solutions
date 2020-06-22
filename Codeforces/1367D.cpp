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
const ll nax=2e5+1;
void solve(){
    string s,temp;
    cin>>s;
    ll n;
    cin>>n;
    vector<pair<ll,ll> > v(n);
    char ans[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i].first;
        v[i].second=i;
        ans[i]='#';
    }
    ll cnt=0;
    temp=s;
    sort(temp.begin(), temp.end());
    //cout<<temp<<endl;
    while(cnt<n){
        vector<ll> ind;
        for (int i = 0; i < n; ++i)
        {
            if(ans[i]=='#' && v[i].first==0){
                ind.pb(i);
                //cout<<i<<endl;            
            }
        }
        //cout<<"IND :"<<ind.size()<<endl;
        ll k=1,x=temp.size()-1;
        //cout<<"X: "<<x<<" ";
        if(ind.size()>1){
            for (int i = temp.size()-2; i >= 0; --i)
            {
                if(temp[i]==temp[i+1]){
                    k++;
                    x=i;
                }
                else if(temp[i]!=temp[i+1] && k<ind.size())
                    k=1;
                else if(temp[i]!=temp[i+1])
                    break;
            }
        }
        //cout<<"X: "<<x<<" ";
        while(x>0 && temp[x]==temp[x-1])
            x--;
        cnt+=ind.size();
        //cout<<"X: "<<x<<endl;
        for (int j = 0; j < ind.size(); ++j)
        {
            ans[ind[j]]=temp[x];
        }
        for (int i = 0; i < n; ++i)
        {
            if(v[i].first>0){
                for (int j = 0; j < ind.size(); ++j)
                {
                    v[i].first-=abs(v[i].second-ind[j]);
                }
            }
        }
        //cout<<endl;
        temp=temp.substr(0,x);
        //cout<<temp<<endl;
    }
    for (int i = 0; i < n; ++i)
    {
        cout<<ans[i];
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    cin>>t;
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