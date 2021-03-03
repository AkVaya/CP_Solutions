class Solution {
public:
    void uni(char f,char s,int *p){
        p[par(s,p)] = p[par(f,p)];
    }
    int par(char s,int *p){
        int x = s-'a';
        while(x!=p[x])
            x = p[x];
        return x;
    }
    bool equationsPossible(vector<string>& equations) {
        int p[26];
        for(int i = 0; i < 26; ++i)
            p[i] = i;
        bool check = false;
        for(auto i : equations){
            if(i[1]=='=')
                uni(i[0], i[3], p);
            
        }
        for(auto i : equations){
            if(i[1]=='!' && par(i[0],p)==par(i[3],p)){
                check = true;
                break;
            }
            
        }
        
        return !check;
    }
};