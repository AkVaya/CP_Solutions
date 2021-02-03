class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 1, start = 0;
        int n = s.length();
        for(int i = 1; i < n; ++i){
            int l = i-1, r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(mx<r-l+1){
                    mx = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
            l = i-1;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(mx<r-l+1){
                    mx = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
            //cout<<i<<' '<<l<<' '<<r<<;
        }
        //cout<<mx<<' '<<start<<endl;
        string res = "";
        for(int i = start; i < start + mx; ++i)
            res+=s[i];
        return res;
    }
};