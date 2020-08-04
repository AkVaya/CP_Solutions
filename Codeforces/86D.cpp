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
#define endl '\n'
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e5+1;
const ll inf=9e18+69;
const ll maxVal=1e6+1;
using pii = pair<ll,ll>;
ll currAns;
ll cnt[maxVal];
vector<ll> answers;
ll partition_size;
ll a[nax],n;
vector<pair<pii,ll> >queries;
bool mo_cmp(const pair<pii,ll> &x, const pair<pii,ll> &y){
    if(x.first.first/partition_size!=y.first.first/partition_size)
        return x.first.first/partition_size<y.first.first/partition_size;
    return x.first.second<y.first.second;
}
void add(ll x){
    currAns-=(cnt[x]*cnt[x]*x);
    ++cnt[x];
    currAns+=(cnt[x]*cnt[x]*x);
}
void remove(ll x){
    currAns-=(cnt[x]*cnt[x]*x);
    --cnt[x];
    currAns+=(cnt[x]*cnt[x]*x);
}
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll q;
    cin>>n>>q;
    queries.resize(q);
    answers.resize(q);
    partition_size=700;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < q; ++i)
    {
        cin>>queries[i].first.first>>queries[i].first.second;
        queries[i].first.first--;
        queries[i].first.second--;
        queries[i].second=i;
    }
    sort(queries.begin(), queries.end(),mo_cmp);
    ll mo_left=0,mo_right=-1;
    for (int i = 0; i < q; ++i)
    {
        ll left=queries[i].first.first;
        ll right=queries[i].first.second;
        //cout<<left<<' '<<right<<':'<<mo_left<<' '<<mo_right<<endl;
        while(mo_right<right){
           	++mo_right;
            add(a[mo_right]);
        }
        while(mo_right>right){
            remove(a[mo_right]);
            --mo_right;
        }
        while(mo_left<left){
            remove(a[mo_left]);
            ++mo_left;
        }
        while(mo_left>left){
            --mo_left;
            add(a[mo_left]);
        }
        answers[queries[i].second]=currAns;
    }
    for (int i = 0; i < q; ++i)
    {
        cout<<answers[i]<<endl;
    }
}
int main(){

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