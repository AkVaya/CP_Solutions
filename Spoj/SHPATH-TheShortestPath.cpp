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
const ll inf=1e18;
using pii = pair<ll,ll>;
map<string,int> city;
vector<vector<pii> > neighbors;
vector<ll> dist;
ll n;
typedef bool (*comp)(pii,pii);
bool compare(pii a,pii b){
	return a.second>b.second;
}
void dijkstras(int source,int destination){
	priority_queue<pii,vector<pii>,comp> pq(compare);
	pq.push(pii(source,0));
	dist[source]=0;
	while(!pq.empty()){
		pii x = pq.top();
		int top=x.first;
		pq.pop();
		if(top==destination)break;
		if(dist[top]<x.second){
			continue;
		}
		for(int i = 0 ; i < neighbors[top].size(); ++i){
			pii neighbor = neighbors[top][i];
			ll in = neighbor.first, cost = neighbor.second;
			if(dist[in]>dist[top]+cost){
				dist[in]=dist[top]+cost;
				pq.push(pii(in,dist[in]));
			}
		}
	}
}

void solve(){
    cin>>n;
	neighbors = vector<vector<pii> > (n,vector<pii>());
	for(int i = 0 ; i < n; ++i){
		string name;
		cin>>name;
		city[name]=i;
		ll num;
		cin>>num;
		while(num--){
			ll x,wt;
			cin>>x>>wt;
			neighbors[i].push_back(pii(x-1,wt));
		}
	}
	ll q;
	cin>>q;
	while(q--){
		string from,to;
		cin>>from>>to;
		dist = vector<ll>(n,inf);
		dijkstras(city[from],city[to]);
		cout<<dist[city[to]]<<endl;
	}
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