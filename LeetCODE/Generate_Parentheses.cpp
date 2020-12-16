class Solution {
public:
    void backtrack(vector<string> &ans,string curr,int cnt1,int cnt2,int n){
        if(cnt2>cnt1 || cnt2>n || cnt1>n)
            return;
        if(cnt1==n && cnt2==n){
            ans.push_back(curr);
            return;
        }
        backtrack(ans,curr+"(",cnt1+1,cnt2,n);
        backtrack(ans,curr+")",cnt1,cnt2+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res,"",0,0,n);
        return res;
    }
};