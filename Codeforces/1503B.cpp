#include<bits/stdc++.h> 
using namespace std; 
const int nax = 3e5 + 69;
using ll = long long;
vector<int> pref(nax, 0);
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	string s, t;
    	cin>>s>>t;
    	pref[0] = (s[0]=='1' ? 1 : -1);
    	for (int i = 1; i < n; ++i)
    	{
    		pref[i] = pref[i-1] + (s[i]=='1' ? 1 : -1);
    	}
    	bool check = true;
    	int i = n-1;
		while(i>=0){
		    while(i>=0 && s[i]==t[i])
		    	i--;
		    if(i>=0 && pref[i]){
		    	check = false;
		    	break;
		    }
		    while(i>=0 && s[i]!=t[i])
		    	i--;
		    if(i>=0 &&pref[i]){
		    	check = false;
		    	break;
		    }
		}
		cout<<(check ? "YES\n" : "NO\n");

    }
	return 0;
} 