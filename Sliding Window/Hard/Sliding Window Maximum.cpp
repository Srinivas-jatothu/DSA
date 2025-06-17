// leetcode problem : https://leetcode.com/problems/sliding-window-maximum/description/

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0;
        deque<int> dq;  
        vector<int> res;

        int n = nums.size();

        while (j < n) {
            // Remove all smaller elements from the back of the deque
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            // If window size < k, just expand the window
            if (j - i + 1 < k) {
                j++;
            }
            // When window size == k
            else if (j - i + 1 == k) {
                res.push_back(nums[dq.front()]);  // The front has the maximum

                // Remove the element going out of the window
                if (dq.front() == i)
                    dq.pop_front();

                // Slide the window
                i++;
                j++;
            }
        }

        return res;
    }
};



/*
Algorithm Explanation:
1. Initialize two pointers `i` and `j` to represent the start and end of the sliding window, respectively.
2. Use a deque `dq` to store indices of the elements in the current window, ensuring that the elements are in decreasing order.
3. Iterate through the array with pointer `j`:
    - While the back of the deque has elements smaller than the current element `nums[j]`, pop them from the back. This ensures that the largest element's index remains at the front of the deque.
    - Push the current index `j` to the back of the deque.
    - If the current window size is less than `k`, simply increment `j` to expand the window.
    - If the current window size equals `k`, append the maximum element (the element at the front of the deque) to the result vector `res`.
      - If the front of the deque is equal to `i`, it means that element is going out of the window, so pop it from the front.
      - Increment both `i` and `j` to slide the window forward.
4. Continue this process until the end of the array is reached.
5. Return the result vector `res`, which contains the maximum elements for each sliding window of size `k`.
6. Time Complexity: O(n), where n is the number of elements in the input vector `nums`. Each element is processed at most twice (once when added and once when removed from the deque).
*/