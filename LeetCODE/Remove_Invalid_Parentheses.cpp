class Solution {
public:
    bool valid(string s){
        int x = 0;
        for(auto i : s){
            if(i=='(')
                x++;
            else if(i==')'){
                x--;
                if(x<0)
                    return false;
            }
        }
        return x==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        q.push(s);
        string temp;
        unordered_set<string> all;
        all.insert(s);
        while(q.size()){
            s = q.front();
            q.pop();
            if(valid(s)){
                res.push_back(s);
            }
            if(res.size())
                continue;
            for(int i = 0; i < s.length(); ++i){
                if(s[i]!=')' && s[i]!='(' )
                    continue;
                temp = s.substr(0, i) + s.substr(i+1);
                if(all.find(temp)==all.end()){
                    all.insert(temp);
                    q.push(temp);
                }
            }
        }
        return res;
    }
};