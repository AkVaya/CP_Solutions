#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		string a,b;
		cin>>n>>k>>a>>b;
		vector<int> cnt1(27,0),cnt2(26,0);
		for (int i = 0; i < n; ++i)
		{
			cnt1[a[i]-'a']++;
			cnt2[b[i]-'a']++;
		}
		bool check=true;
		for (int i = 0; i < 26; ++i)
		{
			if(cnt2[i]>cnt1[i] || (cnt1[i]-cnt2[i])%k){
				check=false;
				break;
			}
			cnt1[i]-=cnt2[i];
			cnt1[i+1]+=cnt1[i];
		}
		cout<<(check ? "Yes\n" : "No\n");
	}
	return 0;
}