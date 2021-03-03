class Solution {
public:
    int myAtoi(string s) {
        long long i = 0,res = 0;
        bool neg = false;
        int cnt = 0;
        while(i<s.length() && s[i]==' ')
            i++;
        if(i<s.length() && s[i]=='-'){
            neg = true;
            i++;
        }
        else if(i<s.length() && s[i]=='+')
            i++;
        while(cnt<=10 && i<s.length() && s[i]>='0' && s[i]<='9'){
            res*=10LL;
            res+=(long long)((neg ? -1 : 1)*(s[i]-'0'));
            if(res)
                cnt++;
            //cout<<res<<endl;
            i++;
        }
        if(cnt>10){
            return (!neg ? INT_MAX : INT_MIN);
        }
        //cout<<res<<endl;
        return ((res<=INT_MAX && res>=INT_MIN) ? res : (!neg ? INT_MAX : INT_MIN) );
    }
};