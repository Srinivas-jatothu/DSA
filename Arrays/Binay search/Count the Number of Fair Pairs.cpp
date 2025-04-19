// leetcode probelm : https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2025-04-19

class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            int n=nums.size();
            long long result=0;
            sort(begin(nums),end(nums));
            for(int i=0;i<n;i++){
                int idx=lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums);
                int x= idx-i-1;
                idx=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums);
                int y=idx-1-i;
                result+=(y-x);
    
            }
            return result;
            
        }
    };


    /*
    Algorithm explanation:
    1. The function countFairPairs takes a vector of integers nums and two integers lower and upper as input.
    2. It initializes a variable n to the size of the nums vector and a variable result to 0.
    3. The nums vector is sorted in ascending order using the sort function.
    4. A loop iterates through each element in the nums vector using the index i.   
    5. For each element nums[i], the lower_bound function is used to find the index idx of the first element in the sorted nums vector that is greater than or equal to lower - nums[i].
    6. The variable x is calculated as the difference between idx and i - 1, which represents the number of elements that are less than lower - nums[i].
    7. The upper_bound function is used to find the index idx of the first element in the sorted nums vector that is greater than upper - nums[i].
    8. The variable y is calculated as the difference between idx and i - 1, which represents the number of elements that are less than or equal to upper - nums[i].
    9. The difference between y and x is added to the result variable, which counts the number of fair pairs for the current element nums[i].
    10. The loop continues until all elements in the nums vector have been processed.
    11. Finally, the function returns the result variable, which represents the total number of fair pairs in the nums vector that satisfy the given conditions.
    */