// leetcode problem : https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/?envType=daily-question&envId=2025-04-09

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            int count=0;
            for (int i : nums) {
                if(i<k) return -1;
                if(i==k) count++;
                mp[i]++;
    
            }
            if(count>0){
                return mp.size()-1;
            }
            else{
                return mp.size();
            }
    
        }
    };

    /*
    Algorithm Explanation:
    1. Create an unordered map `mp` to store the frequency of each element in the input vector `nums`.
    2. Initialize a variable `count` to keep track of the number of occurrences of the target value `k`.
    3. Iterate through each element `i` in the input vector `nums`.
    4. If `i` is less than `k`, return -1, as it is not possible to make all elements equal to `k`.
    5. If `i` is equal to `k`, increment the `count` variable.
    6. Update the frequency of `i` in the unordered map `mp`.
    7. After iterating through all elements, check if `count` is greater than 0.
    8. If it is, return the size of the unordered map `mp` minus 1, as we can ignore one occurrence of `k`.
    9. If `count` is not greater than 0, return the size of the unordered map `mp`, as we need to include all unique elements in the result.
    10. The time complexity of this algorithm is O(n), where n is the size of the input vector `nums`, as we are iterating through the array only once.
    */