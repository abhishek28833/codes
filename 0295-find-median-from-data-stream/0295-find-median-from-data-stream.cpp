class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0) maxHeap.push(num);
        else if(maxHeap.top() < num) minHeap.push(num);
        else maxHeap.push(num);

        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }else if(maxHeap.size()-1 > minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        int total = minHeap.size() + maxHeap.size();
        if((total&1)) return maxHeap.top();
        double a = minHeap.top();
        double b = maxHeap.top();
        return (a+b)/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */