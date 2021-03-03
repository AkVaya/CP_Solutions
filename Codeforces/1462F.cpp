#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
	while(t--){
		int n;
	    cin>>n;
	    vector<int> finish(n),start(n);
	    vector<pair<int,int> >all(n);
	    for (int i = 0; i < n; ++i){

	    	cin>>all[i].first>>all[i].second;
	    	start[i] = all[i].first;
	    	finish[i] = all[i].second;
	    }
	    int res = 0;
	    sort(finish.begin(),finish.end());
	    sort(start.begin(),start.end());
	    for (int i = 0; i < n; ++i)
	    {
	    	int it1 = n - (upper_bound(start.begin(),start.end(),all[i].second) - start.begin());
	    	int it2 = (lower_bound(finish.begin(),finish.end(),all[i].first) - finish.begin());
	    	res = max(res,n-it1-it2);
	    }
	    //cout<<res<<' ';
	    cout<<n-res<<'\n';
    }
    return 0;
}