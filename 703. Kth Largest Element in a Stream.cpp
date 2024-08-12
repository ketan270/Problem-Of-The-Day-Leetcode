#include <queue>
#include <vector>

class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int K;

    KthLargest(int k, std::vector<int>& nums) {
        K = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > K) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > K) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
