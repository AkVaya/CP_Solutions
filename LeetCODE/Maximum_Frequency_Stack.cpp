class FreqStack {
public:
    unordered_map<int,int> cnt;
    unordered_map<int,stack<int> > each;
    int mx = 0;
    FreqStack() {
        cnt.clear();
        for(auto i : each)
            while(i.second.size())
                i.second.pop();
        mx = 0;
    }
    
    void push(int x) {
        
        cnt[x]++;
        if(mx<cnt[x])
            mx = cnt[x];
        each[cnt[x]].push(x);
        //for(auto i : each)
            //cout<<i.first<<' '<<i.second.size()<<endl;
        //cout<<endl;
    }
    
    int pop() {
        while(each[mx].size() && !cnt[each[mx].top()]){
            each[mx].pop();
            if(!each[mx].size())
                mx--;
        }
        int val = each[mx].top();
        each[mx].pop();
        if(!each[mx].size())
            mx--;
        cnt[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */