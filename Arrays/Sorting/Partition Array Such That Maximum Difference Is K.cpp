// leetcode problem : https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/?envType=daily-question&envId=2025-06-19

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=1;
        int n=nums.size();
        int mini=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]-mini >k){
                res++;
                mini=nums[i];
            }
        }
        return res;
    }
};

/*
Algorithm Explanation:
1. Sort the input array `nums` in ascending order.
2. Initialize a variable `res` to 1, which will count the number of partitions.
3. Set `mini` to the first element of the sorted array.
4. Iterate through the sorted array:
   - If the difference between the current element and `mini` exceeds `k`, increment `res` and update `mini` to the current element.
5. Return the value of `res`, which represents the number of partitions needed such that the maximum difference in each partition is at most `k`.
Time Complexity: O(n log n) due to sorting, where n is the number of elements in the array.
Space Complexity: O(1) for the partitioning logic, as we are using a constant amount of extra space.
*/