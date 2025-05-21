// leetcode problem: https://leetcode.com/problems/zero-array-transformation-i/description/?envType=daily-question&envId=2025-05-20

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        //Step-1 Make diff array using query
        vector<int> diff(n, 0);
        for(auto &query : queries) {
            int start = query[0];
            int end   = query[1];
            int x     = 1;

            diff[start] += x;
            if(end+1 < n) {
                diff[end+1] -= x;
            }
        }

        //Step-2. Find cumulative effect on each index
        vector<int> result(n, 0);
        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];
            result[i] = cumSum;
        }

        for(int i = 0; i < n; i++) {
            if(result[i] < nums[i]) { //nums[i] won't become 0 ever
                return false;
            }
        }

        return true;
    }
};


/*
Algorithm explanation:
1. Initialize a difference array `diff` of size `n` (length of `nums`) to keep track of the cumulative effect of the queries.
2. For each query, update the `diff` array to mark the start and end of the increment.
3. Calculate the cumulative effect on each index of the `diff` array to get the final result.
4. Compare the final result with the original `nums` array.
5. If any element in `result` is less than the corresponding element in `nums`, return false.
6. If all elements in `result` are greater than or equal to the corresponding elements in `nums`, return true.
7. The time complexity is O(n + m), where n is the size of `nums` and m is the number of queries.

*/