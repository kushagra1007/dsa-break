class MedianFinder {
    priority_queue<int, vector<int>> lowerQueue;
    priority_queue<int, vector<int>, greater<int>> upperQueue;
public:
    MedianFinder() {
        
    }

    void balance() {
        if (upperQueue.size() > lowerQueue.size()) {
            while (upperQueue.size() > lowerQueue.size()) {
                int trans = upperQueue.top();
                upperQueue.pop();
                lowerQueue.push(trans);
            }
        }  
        if (upperQueue.size() + 1 < lowerQueue.size()) {
            while (upperQueue.size() + 1 < lowerQueue.size()) {
                int trans = lowerQueue.top();
                lowerQueue.pop();
                upperQueue.push(trans);
            }
        }
    }
    
    void addNum(int num) {
        if (lowerQueue.empty() || num <= lowerQueue.top()) {
            lowerQueue.push(num);
        } else {
            upperQueue.push(num);
        }
        balance();
    }
    
    double findMedian() {
        if (lowerQueue.size() > upperQueue.size()) {
            return lowerQueue.top();
        } else {
            return (lowerQueue.top() + upperQueue.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */