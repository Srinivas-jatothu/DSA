// leetcode problem : https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/?envType=daily-question&envId=2025-06-28

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n)
            return nums;

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = make_pair(i, nums[i]);
        }

        auto lambda = [](auto &p1, auto& p2) {
            return p1.second > p2.second;
        };

        sort(begin(vec), end(vec), lambda);

        sort(begin(vec), begin(vec)+k);

        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(vec[i].second);
        }

        return result;
    }
};

/*
Algorithm Explanation:
1. The function `maxSubsequence` takes a vector of integers `nums` and an integer `k` as input.
2. It checks if `k` is equal to the size of `nums`. If so, it returns the entire `nums` vector since all elements are needed.
3. It creates a vector of pairs `vec` where each pair contains the index and value of each element in `nums`.
4. It defines a lambda function to sort the pairs in descending order based on their values.
5. It sorts the `vec` vector using the lambda function.
6. It then sorts the first `k` elements of `vec` based on their original indices to maintain the order of elements in the original array.
7. Finally, it constructs a result vector containing the values of the first `k` elements from the sorted `vec` and returns it.
Time Complexity: O(n log n) due to sorting operations.
Space Complexity: O(n) for storing the pairs in `vec`.
*/