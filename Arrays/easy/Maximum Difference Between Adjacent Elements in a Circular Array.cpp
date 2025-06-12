// leetcode problem : https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-question&envId=2025-06-12https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-question&envId=2025-06-12

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxi=abs(nums[n-1]-nums[0]);
        int diff;
        for(int i=0;i<n-1;i++){
            diff=abs(nums[i]-nums[i+1]);
            if(maxi<diff){
                maxi=diff;
            }
        }
        return maxi;
    }
};


/*
Algorithm Explanation:
1. Initialize the size of the array `n` and set `maxi` to the absolute difference between the last and first elements.
2. Iterate through the array from the first to the second last element.
3. For each adjacent pair of elements, calculate the absolute difference.
4. If the calculated difference is greater than the current `maxi`, update `maxi`.
5. Finally, return `maxi` as the maximum difference between adjacent elements in the circular array.
6. The time complexity of this solution is O(n), where n is the number of elements in the array.
*/