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
#define M 10000007
using namespace std;
bool customSort(vector<ll> a, vector<ll> b){
    if(a[1] > b[1])
        return true;
    if(a[1] == b[1])
        return a[2] < b[2];
    return false;
}
int main(){
    ll n, c, x, pos=1;
    map<ll, ll> count, position;
    vector< vector<ll> > result;
    cin>>n>>c;
    for(ll i=0;i<n;i++){
        cin>>x;
        if(count[x] == 0)
            count[x] = 1;
        else count[x]++;

        if(position[x] == 0)
            position[x] = pos++;
    }
    for(map<ll, ll>::iterator it = count.begin();it != count.end();it++){
        vector<ll> tmp;
        tmp.pb(it->first);
        tmp.pb(it->second);
        tmp.pb(position[it->first]);
        result.pb(tmp);
    }
    sort(result.begin(), result.end(), customSort);
    for(ll i=0;i<result.size();i++){
        for(ll j=0;j<result[i][1];j++)
            cout<<result[i][0]<<" ";
    }
    return 0;
}