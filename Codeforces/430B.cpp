#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,x,ans=0;
	cin>>n>>k>>x;
	int a[n];
	for(int i = 0; i < n; ++i){
		cin>>a[i];
	}
	for (int i = 1; i < n-2; ++i)
	{
		int curr = 0;
		int left = i-1, right = i+2;
		//cout<<i<<' '<<a[i]<<' '<<a[i+1]<<endl;
		if(a[i]==x && a[i+1]==x){
			curr+=2;
			while(left>=0 && right<n){
				int cnt = 0;
				int val = a[left];
				while(left>=0 && val==a[left]){
					cnt++;
					left--;
				}
				while(right<n && val==a[right]){
					cnt++;
					right++;
				}
				if(cnt<3){
					break;
				}
				curr+=cnt;
			}
		}
		ans=max(ans,curr);
	}
	cout<<ans<<endl;
    return 0;
}   