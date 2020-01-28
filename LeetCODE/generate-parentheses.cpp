class Solution {
public:
    bool isValid(string s) {
        long long int l =s.length();
        if(l==0)
            return true;
        stack<int> s1;
        for(int i=0;i<l;i++){
            if(s[i]=='('){
                s1.push(1);
            }
            else if(s[i]=='{'){
                s1.push(2);
            }
            else if(s[i]=='['){
                s1.push(3);
            }
            else if(s[i]==')' && !s1.empty()){
                if(s1.top()==1)
                    s1.pop();
                else 
                    return false;
            }
            else if(s[i]=='}' && !s1.empty()){
                if(s1.top()==2)
                    s1.pop();
                else 
                    return false;
            }
            else if(s[i]==']' && !s1.empty()){
                if(s1.top()==3)
                    s1.pop();
                else 
                    return false;
            }
            else 
                return false;
        }
        if(s1.empty()){
            return true;
        }
        else 
            return false;
        
    }
};