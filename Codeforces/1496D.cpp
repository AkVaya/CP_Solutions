#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
const ll M = 1e9 + 7;
int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int mxI = 1,indI = 0, mxD = 1, indD = 0,cnt1 = 0,cnt2 = 0;
	int currI = 1, currD = 1;
	for (int i = 1; i < n; ++i)
	{
		if(a[i]>a[i-1]){
			currI++;
			if(mxI<=currI){
				mxI = currI;
				indI = i - mxI + 1;
				cnt1 = 1;
			}
			else if(mxI == currI)
				cnt2++;
		}
		else
			currI = 1;
		if(a[i]<a[i-1]){
			currD++;
			if(mxD<currD){
				mxD = currD;
				indD = i - mxD + 1;
				cnt2 = 1;
			}
			else if(mxD == currD)
				cnt2++;
		}
		else
			currD = 1;
	}
	//cout<<mxI<<' '<<mxD<<endl;
	//cout<<indD<<' '<<(indI + mxI -1)<<endl;
	//cout<<cnt1<<' '<<cnt2<<endl;
	if(mxI != mxD || indD != (indI + mxI -1) || mxI%2==0 || cnt1!=1 || cnt2!=1)
		cout<<"0\n";
	else
		cout<<"1\n";
	return 0;
}