#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 69;
int n,a[nax],k;
set<int> s,others;
bool check(int val){
	if(s.size()>=val)
		return true;
	set<int> curr = s;
	for(auto i : others)
		if(curr.find(i/k)==curr.end())
			curr.insert(i);
	return curr.size()>=val;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(a[i]%k)
        	s.insert(a[i]);
        else
        	others.insert(a[i]);
    } 
    int l = 0,r = n+1;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid))
            l = mid + 1;
        else r = mid - 1;
    }
    cout<<l-1<<'\n';
    return 0;
}