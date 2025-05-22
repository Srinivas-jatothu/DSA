// leetcode problem : https://leetcode.com/problems/zero-array-transformation-iii/description/?envType=daily-question&envId=2025-05-22

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> past;

        priority_queue<int> maxHeap;

        sort(queries.begin(), queries.end());

        int j = 0;             
        int usedCount = 0;     
        for (int i = 0; i < n; ++i) {
            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]); 
                ++j;
            }
            nums[i] -= past.size();

            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                int r = maxHeap.top(); maxHeap.pop();
                past.push(r);
                usedCount++;
                nums[i]--;
            }

            if (nums[i] > 0)
                return -1;
            while (!past.empty() && past.top() == i) {
                past.pop();
            }
        }

        return queries.size() - usedCount;
    }
};



/*
Algorithm explanation:
1. Initialize two priority queues: `past` to keep track of the indices that have been used and `maxHeap` to store the maximum values from the queries.
2. Sort the `queries` based on the first element of each query.
3. Iterate through the `nums` array and for each index `i`, check if there are any queries that start at this index.
4. For each query, push the second element (the maximum value) into `maxHeap`.
5. Decrease the value of `nums[i]` by the size of `past` to account for the indices that have already been used.
6. While `nums[i]` is greater than 0 and `maxHeap` is not empty, check if the top of `maxHeap` is greater than or equal to `i`.
7. If it is, pop the top element from `maxHeap`, push it into `past`, and decrement `nums[i]`.
8. If `nums[i]` is still greater than 0 after processing all queries, return -1.
9. If all elements in `nums` are processed successfully, return the difference between the size of `queries` and the number of used indices.
10. The time complexity is O(n + m log m), where n is the size of `nums` and m is the number of queries.
11. The space complexity is O(n + m) for the two priority queues.
*/