//leetcode problem : https://leetcode.com/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07



class Solution {
    public:
        int t[201][20001];
        bool solve(vector<int>& nums, int i, int x) {
            if(x == 0) {
                return true;
            }
            if(i >= nums.size()) {
                return false;
            }
            if(t[i][x] != -1) {
                return t[i][x];
            }
            bool take = false;
            if(nums[i] <= x) {
                take = solve(nums, i+1, x - nums[i]);
            }
            bool not_take = solve(nums, i+1, x);
            return t[i][x] = take || not_take;
        }
    
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int S = accumulate(begin(nums), end(nums), 0);
            if(S%2 != 0) {
                return false;
            }  
            memset(t, -1, sizeof(t));
            int x = S/2;
            return solve(nums, 0, x);
    
        }
    };



    /*
    Algorithm explanation:
    1. The function `canPartition` checks if the given array `nums` can be partitioned into two subsets with equal sum.
    2. It first calculates the total sum `S` of the elements in `nums` using `accumulate`.
    3. If `S` is odd, it returns false because it's impossible to partition an odd sum into two equal parts.
    4. It initializes a 2D array `t` of size `[201][20001]` to store the results of subproblems, and fills it with -1 to indicate uncomputed states.
    5. It calculates the target sum `x` as half of `S`.
    6. The recursive function `solve` is called with the initial index `0` and target sum `x`.
    7. Inside `solve`, if the target sum `x` becomes `0`, it returns true, indicating that a valid partition has been found.
    8. If the index `i` exceeds the size of `nums`, it returns false, indicating that no valid partition can be formed.
    9. If the result for the current index `i` and target sum `x` is already computed (not -1), it returns the stored result.
    10. It checks if the current element `nums[i]` can be included in the subset by comparing it with `x`. If it can, it recursively calls `solve` for the next index and the reduced target sum (`x - nums[i]`).
    11. It also checks the case where the current element is not included in the subset by calling `solve` for the next index and the same target sum `x`.
    12. The result is stored in `t[i][x]` and returned.
    13. Finally, the result of `solve` is returned from the `canPartition` function, indicating whether the array can be partitioned into two subsets with equal sum.
    */