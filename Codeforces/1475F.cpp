#include<bits/stdc++.h>
using namespace std;
const int nax = 1e7 + 69;
const int M = 1e9 + 7;
using ll = long long;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s1[n],s2[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>s1[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>s2[i];
		}
		vector<bool> r(n,false),c(n,false);
		for (int i = 0; i < n; ++i)
		{
			if(s1[i][0]!=s2[i][0]){
				r[i] = true;
				for(int k = 0; k < n; ++k)
					s1[i][k] = '1' - s1[i][k] + '0';
			}
		}
		for (int j = 0; j < n; ++j)
		{
			if(s1[0][j]!=s2[0][j]){
				c[j] = true;
				for(int k = 0; k < n; ++k)
					s1[k][j] = '1' - s1[k][j] + '0';
			}
		}
		bool check = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(s1[i][j]!=s2[i][j]){
					if(!c[i]){
						for(int k = 0; k < n; ++k){
							s1[k][j] = '1' - s1[k][j] + '0';
						}
						c[i] = true;
					}
					else if(!r[i]){
						r[i] = true;
						for(int k = 0; k < n; ++k)
							s1[i][k] = '1' - s1[i][k] + '0';
					}
					else{
						check = false;
						break;
					}
				}
			}
			if(!check)
				break;
		}
		for (int j = 0; j < n; ++j)
		{
			for (int i = 0; i < n; ++i)
				if(s1[i][j]!=s2[i][j])
					check = false;
			if(!check)
				break;
		}
		cout<<(check ? "YES" : "NO")<<endl;
		
	}
	return 0;
}