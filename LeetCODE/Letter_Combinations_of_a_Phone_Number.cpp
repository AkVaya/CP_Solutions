class Solution {
public:
    void backtrack(vector<string> &res,string curr, string &digits,int ind){
        if(ind==digits.length()){
            res.push_back(curr);
            return;
        }
        int temp = digits[ind] - '2';
        for(int i = 0;i < 3 + (digits[ind]=='7' || digits[ind]=='9'); ++i){
            char x = i + temp*3 + 'a';
            if(temp>5)
                x++;
            backtrack(res,curr+x,digits,ind+1);
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string> res;
        if(!digits.length())
            return res;
        string temp="";
       backtrack(res,temp,digits,0); 
       return res;
    }
};