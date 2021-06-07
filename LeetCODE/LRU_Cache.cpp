class LRUCache {
public:
    list<pair<int, int> > l;
    unordered_map<int, list<pair<int, int> >::iterator> m;
    int mx;
    LRUCache(int capacity) {
        mx = capacity;
        l.clear();
        m.clear();
    }
    
    int get(int key) {
        int res = -1;
        if(m.count(key)){
            res = (*m[key]).second;
            l.erase(m[key]);
            l.push_front({key, res});
            m[key] = l.begin();
        }
        return res;
    }
    
    void put(int key, int value) {
        if(!m.count(key)){
            if(l.size()==mx){
                m.erase(l.back().first);
                l.pop_back();
            }
        }    
        else
            l.erase(m[key]);
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */