#include<bits/stdc++.h>
using namespace std;
const long long nax = 2e3 + 1;
int n,a[nax];
unordered_map<int,int> all,sec;
bool check(int val){
	for (int i = 0; i <= n-val; ++i)
	{
		unordered_map<int,int> temp = sec;
		for (int j = 0; j < val; ++j)
			temp[a[j+i]]--;
		bool check=true;
		for(auto i : temp)
			if(i.second>1){
				check = false;
				break;
			}
		if(check)
			return true;
	}
	return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    	all[a[i]]++;
    }
    for(auto i : all)
    	if(i.second>1)
    		sec[i.first] = i.second;
    int l = 0,r = n-1;
    while(l<=r){
    	long long mid = (l+r)/2;
    	if(check(mid))
    		r = mid - 1;
    	else l = mid + 1;
    }
    cout<<r + 1<<'\n';
    return 0;
}