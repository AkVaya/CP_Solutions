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
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
const ll M =1e9+7;
const ll nax=200001;
void solve(){
    int m,n,ans=0;
    string s1,s2;
    cin>>s1>>s2;
    vector<ll> v[26];
    for (int i = 0; i < s1.length(); ++i)
    {
    	v[s1[i]-'a'].eb(i);
    }
    bool check=false;
    ll ind=-1;
    for (int i = 0; i < s2.length(); ++i)
    {
    	if(v[s2[i]-'a'].size()==0){
    		check=true;
    		break;
    	}
    	else{
    		auto it=upper_bound(v[s2[i]-'a'].begin(),v[s2[i]-'a'].end(),ind);
    		if(it==v[s2[i]-'a'].end()){
    			ans++;
    			ind=*v[s2[i]-'a'].begin();
    		}
    		else
    			ind=*it;
    	}
    }
    if(check){
    	cout<<-1<<endl;
    	return ;
    }
    else
    	cout<<ans+1<<endl;
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
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}