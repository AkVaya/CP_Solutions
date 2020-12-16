#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		string s[n];
		map<string,vector<int> >m,problem;
		for (int i = 0; i < n; ++i)
		{
			cin>>s[i];
			m[s[i]].push_back(i);
		}
		int res = 0;
		for(auto i : m){
			if(i.second.size()==1)
				continue;
			for(int j = 1; j < i.second.size(); ++j){
				bool check = false;
				for (int k = 0; k < 4; ++k)
				{
					for(char x = '0'; x <= '9'; x++){
						char temp = s[i.second[j]][k];
						s[i.second[j]][k] = x;
						if(!m[s[i.second[j]]].size()){
							m[s[i.second[j]]].push_back(i.second[j]);
							res++;
							check = true;
							break;
						}
						else
							s[i.second[j]][k] = temp;
					}
					if(check)
						break;
				}
			}
		}
		cout<<res<<endl;
		for (int i = 0; i < n; ++i)
		{
			cout<<s[i]<<endl;
		}
	}
}   