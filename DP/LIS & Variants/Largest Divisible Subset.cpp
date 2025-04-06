// leetcode problem : https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2025-04-06

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(begin(nums), end(nums));
    
            int n = nums.size();
            vector<int> t(n, 1);
    
            vector<int> prev_idx(n, -1);
            int last_chosen_index = 0;
            int maxL = 1;
    
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < i; j++) {
                    if(nums[i]%nums[j] == 0) {
                        if(t[i] < t[j]+1) {
                            t[i] = t[j]+1;
                            prev_idx[i] = j;
                        }
    
                        if(t[i] > maxL) {
                            maxL = t[i];
                            last_chosen_index = i;
                        }
                    }
                }
            }
    
            vector<int> result;
            while(last_chosen_index >= 0) {
                result.push_back(nums[last_chosen_index]);
                last_chosen_index = prev_idx[last_chosen_index];
            }
    
            return result;
        }
    };

    


    /*
    Algorithm explanation:
    1. The function `largestDivisibleSubset` is designed to find the largest subset of a given list of integers `nums` such that every pair of elements in the subset is divisible.
    2. It starts by sorting the input list `nums` in ascending order.
    3. It initializes a vector `t` of size `n` (the size of `nums`) to keep track of the length of the largest divisible subset ending at each index. Initially, all values are set to 1, as each element can be a subset by itself.
    4. It also initializes a vector `prev_idx` to keep track of the previous index of each element in the largest divisible subset. This helps in reconstructing the subset later.
    5. The variable `last_chosen_index` is used to keep track of the index of the last chosen element in the largest divisible subset, and `maxL` keeps track of the maximum length of the subset found so far.
    6. The outer loop iterates through each element in `nums`, and the inner loop checks all previous elements to see if they can form a divisible pair with the current element.
    7. If a divisible pair is found, it updates the length of the largest divisible subset ending at the current index (`t[i]`) and sets the previous index for that element (`prev_idx[i]`).
    8. If the length of the current subset (`t[i]`) is greater than the maximum length found so far (`maxL`), it updates `maxL` and `last_chosen_index` to the current index.
    9. After processing all elements, it reconstructs the largest divisible subset by following the `prev_idx` array starting from `last_chosen_index` and adds the elements to the result vector.
    10. Finally, it returns the result vector containing the largest divisible subset.
    */