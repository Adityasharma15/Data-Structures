// 295. Find Median from Data Stream

#define ll long long
class MedianFinder {

// Using 2 priority queues:
// first one - a max heap to contain first half of array
// second one - a min heap to contain second half of array
// so, median will basically be first.top() if odd length or
// mean of first.top() or second.top() when length is even

// instead of using min heap, we will insert -1*value to utilise the same thing

public:

priority_queue<ll> first, second;

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {

        first.push(num);
        second.push(-first.top());
        first.pop();

        // if initially they had equal size
        if(first.size() < second.size()){
            first.push(-second.top());
            second.pop();
        }
    }

    double findMedian() {

        // if even length
        if(second.size() == first.size())
            return (first.top() -second.top())/2.000;

        return first.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
