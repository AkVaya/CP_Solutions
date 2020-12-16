#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 69;
map<long long,bool> check;
vector<long long> all;
int k;
void lunlun(long long curr){
	if(curr>3234566667)
		return;
	all.push_back(curr);
	lunlun(curr*10+curr%10);
	if(curr%10)
		lunlun(curr*10+curr%10-1);
	if(curr%10!=9)
		lunlun(curr*10+curr%10+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>k;
    for (int i = 1; i <= 9; ++i)
    {
    	lunlun(i);
    }
    sort(all.begin(), all.end());
    cout<<all[k-1];

	return 0;
}