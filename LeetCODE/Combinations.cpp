class Solution {
public:
    void backtrack(vector<vector<int> >&res,vector<int>& curr,int n,int k){
        if(k==0){
            res.push_back(curr);
            return;
        }
        for(int i = n; i >= 1; --i){
            curr.push_back(i);
            backtrack(res,curr,i-1,k-1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> >res;
        vector<int> curr;
        backtrack(res,curr,n,k);
        return res;
    }
};