// leetcode problem : https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/?envType=daily-question&envId=2025-04-17


class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n=nums.size();
            int count=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if (nums[i] == nums[j] && ((i * j) % k == 0)){
                        count++;
                    }
                }
            }
            return count;
        }
    };



    /*
    Algorithm explanation:
    1. Initialize a variable count to 0 to keep track of the number of valid pairs.
    2. Get the size of the input array nums and store it in n.
    3. Use a nested loop to iterate through all pairs of indices (i, j) in the array.
    4. The outer loop iterates from 0 to n-1, and the inner loop iterates from i+1 to n-1.
    5. For each pair of indices (i, j), check if the elements at those indices are equal (nums[i] == nums[j]).
    6. If they are equal, check if the product of the indices (i * j) is divisible by k ((i * j) % k == 0).
    7. If both conditions are satisfied, increment the count variable by 1.
    8. Continue this process until all pairs have been checked.
    9. Finally, return the count variable, which contains the total number of valid pairs.    
    */