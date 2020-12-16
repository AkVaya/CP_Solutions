#include<bits/stdc++.h>
using namespace std;
const long long nax = 5e4 + 69 ;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    int a[n][4];
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < 4; ++j)
    	{
    		cin>>a[i][j];
    	}
    }
    vector<int> fi,se;
    for (int i = 0; i < n; ++i)
    {
     	for (int j = 0; j < n; ++j)
     	{
     		fi.emplace_back(a[i][0]+a[j][1]);
     		se.emplace_back(a[i][2]+a[j][3]);
     	}
    }
    sort(se.begin(), se.end());
    int ans = 0;
    for (auto i : fi)
    {
    	int ind1 = lower_bound(se.begin(), se.end(),-i) - se.begin();
    	int ind2 = upper_bound(se.begin(), se.end(),-i) - se.begin();
    	ans+=(ind2-ind1);
    }
    cout<<ans<<'\n';
    return 0;
}