#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 69;
long long n,a[nax];
bool check(int val){
	int cnt = 0, l=0;
	for (int i = val; i < n; ++i)
	{
		if(a[i]>a[l]){
			cnt++;
			l++;
		}
		l = min(l,val-1);
	}
	return cnt>=val+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}	
	sort(a,a+n);
	int l = 1,r = n;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid))
			l = mid+1;
		else r = mid-1; 
	}
	cout<<l-1<<'\n';
	r = n-1;
	int temp = l-2;
	while(r>=l-1 && temp>=0){
		cout<<a[r--]<<' '<<a[temp--]<<' ';
	}
	while(r!=l-2)
		cout<<a[r--]<<' ';
	cout<<'\n';
	return 0;
}