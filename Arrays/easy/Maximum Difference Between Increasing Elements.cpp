// leetcode problem : https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/?envType=daily-question&envId=2025-06-16

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int res=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    res=max(res,(nums[j]-nums[i]));
                }
                else{
                    break;
                }
            }
        }

        return res;
    }
};


/*
Algorithm Explanation:
1. Initialize `n` as the size of the input vector `nums` and `res` as -1 to store the maximum difference.
2. Use a nested loop to iterate through each pair of indices `i` and `j` where `j` is always greater than `i`.
3. For each pair, check if `nums[i]` is less than `nums[j]`. If true, calculate the difference and update `res` if this difference is greater than the current `res`.
4. If `nums[i]` is not less than `nums[j]`, break the inner loop since further elements will not yield a valid increasing pair.
5. Finally, return `res`, which will be the maximum difference found or -1 if no valid pairs were found.
6. Time Complexity: O(n^2), where n is the number of elements in the input vector `nums`.
*/