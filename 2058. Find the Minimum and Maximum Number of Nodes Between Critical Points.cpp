/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void findCriticalPoints(const vector<int>& nums, vector<int>& criticalPoints) {
        int n = nums.size();
        for (int i = 1; i < n - 1; ++i) {
            if ((nums[i] > nums[i-1] && nums[i] > nums[i+1]) || (nums[i] < nums[i-1] && nums[i] < nums[i+1])) {
                criticalPoints.push_back(i);
            }
        }
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        vector<int> criticalPts;
        findCriticalPoints(nums, criticalPts);

        if (criticalPts.size() < 2) {
            return {-1, -1};
        }

        int minDistance = INT_MAX;
        int maxDistance = criticalPts.back() - criticalPts.front();

        for (int i = 1; i < criticalPts.size(); i++) {
            minDistance = min( minDistance,criticalPts[i] - criticalPts[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};
