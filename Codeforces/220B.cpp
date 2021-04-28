#include<bits/stdc++.h>
using namespace std;
const int nax=1e5+69;
using pii = pair<int,int>;
int currAns;
int cnt[nax];
vector<int> ans;
int partition_size;
int a[nax],n;
vector<pair<pii,int> >queries;
bool mo_cmp(const pair<pii,int> &x, const pair<pii,int> &y){
    int left_x=x.first.first/partition_size;
    int left_y=y.first.first/partition_size;
    if(left!=right)
        return left_x<left_y;
    return x.first.second<y.first.second;
}
void add(int x){
	if(x>n)
		return;
	if(cnt[x]==x)
		currAns--;
	cnt[x]++;
	if(cnt[x]==x)
		currAns++;
}
void remove(int x){
	if(x>n)
		return;
	if(cnt[x]==x)
		currAns--;
	cnt[x]--;
	if(cnt[x]==x)
		currAns++;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>n>>q;
    queries.resize(q);
    ans.resize(q);
    partition_size=sqrt(n);
    for (int i = 0; i < n; ++i)
        cin>>a[i];
    for (int i = 0; i < q; ++i)
    {
        cin>>queries[i].first.first>>queries[i].first.second;
        queries[i].first.first--;
        queries[i].first.second--;
        queries[i].second=i;
    }
    sort(queries.begin(), queries.end(),mo_cmp);
    int mo_left=0,mo_right=-1;
    for (int i = 0; i < q; ++i)
    {
        int left=queries[i].first.first;
        int right=queries[i].first.second;
        while(mo_right<right){
            mo_right++;
            add(a[mo_right]);
        }
        while(mo_right>right){
            remove(a[mo_right]);
            mo_right--;
        }
        while(mo_left<left){
            remove(a[mo_left]);
            ++mo_left;
        }
        while(mo_left>left){
            --mo_left;
            add(a[mo_left]);
        }
        ans[queries[i].second]=currAns;
    }
    for (int i = 0; i < q; ++i)
    {
        cout<<ans[i]<<'\n';
    }
    return 0 ;
}