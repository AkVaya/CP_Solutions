class Solution {
public:
    void backtrack(vector<vector<int> >&res,vector<int>& curr,vector<int>& a,int sum,int target,int ind){
        if(sum>=target || ind==a.size()){
            if(sum==target)
                res.push_back(curr);
            return;
        }
        curr.push_back(a[ind]);
        int temp = ind+1;
        while(temp<a.size() && a[temp]==a[temp-1])
            temp++;
        backtrack(res,curr,a,sum+a[ind],target,ind+1);
        curr.pop_back();
        backtrack(res,curr,a,sum,target,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> >res;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        backtrack(res,curr,candidates,0,target,0);
        return res;
    }
};