#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    int k;
    cin>>k;
    deque<int>q;
    for (int i = 0; i < k; ++i)
    {
    	while(q.size() && a[q.back()]<a[i])
    		q.pop_back();
    	q.push_back(i);
    }
    for (int i = k; i < n; ++i)
    {
    	cout<<a[q.front()]<<' ';
    	while(q.size() && q.front()<=i-k)
    		q.pop_front();
    	while(q.size() && a[q.back()]<a[i])
    		q.pop_back();
    	q.push_back(i);
    }
    cout<<a[q.front()];
    return 0;
}