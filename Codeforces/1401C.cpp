#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int mn = INT_MAX;
		vector<pair<int,int> > a(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i].first;
			a[i].second = i;
			mn = min(a[i].first,mn);
		}
		sort(a.begin(), a.end());
		bool check = false;
		for (int i = 0; i < n; ++i)
		{
			if(a[i].first%mn && a[i].second!=i){
				check=true;
				break;
			}
		}
		if(check)
			cout<<"NO\n";
		else cout<<"YES\n";

	}

	return 0;
}