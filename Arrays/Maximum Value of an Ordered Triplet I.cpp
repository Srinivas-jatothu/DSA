//leetcode problem : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/?envType=daily-question&envId=2025-04-02


class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = 0, mxDiff = 0;
            int mx = 0;
            for (int x : nums) {
                ans = max(ans, mxDiff * x);
                mxDiff = max(mxDiff, 1LL * mx - x);
                mx = max(mx, x);
            }
            return ans;
        }
    };



    /*
    Algorithm explanation:
    1. Initialize `ans` to 0, `mxDiff` to 0, and `mx` to 0.
    2. Iterate through each element `x` in the `nums` vector.
    3. Update `ans` to be the maximum of its current value and the product of `mxDiff` and `x`.
    4. Update `mxDiff` to be the maximum of its current value and the difference between `mx` and `x` (this represents the maximum difference seen so far).
    5. Update `mx` to be the maximum of its current value and `x` (this represents the maximum value seen so far).
    6. After iterating through all elements, return `ans`, which represents the maximum value of the triplet (a, b, c) where a < b > c.
    7. The result is the maximum value of the triplet (a, b, c) that can be formed from the given array `nums`.
    */