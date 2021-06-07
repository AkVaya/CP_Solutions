class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int> >higher;
    priority_queue<int> lower;
    MedianFinder() {
        while(lower.size())
            lower.pop();
        while(higher.size())
            higher.pop();
    }
    
    void addNum(int num) {
        if(lower.size()==higher.size()){
            if(higher.size() && higher.top()<num){
                higher.push(num);
                lower.push(higher.top());
                higher.pop();
            }
            else{
                lower.push(num);
            }
        }
        else{
            lower.push(num);
            int val = lower.top();
            lower.pop();
            higher.push(val);
        }
    }
    
    double findMedian() {
        if(lower.size()>higher.size())
                return lower.top();
        return ((((double)(lower.top() + higher.top()))/2.0));
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */