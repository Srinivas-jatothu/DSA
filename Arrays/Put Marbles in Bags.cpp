//leetcode problem : https://leetcode.com/problems/put-marbles-in-bags/description/?envType=daily-question&envId=2025-03-31



class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = weights.size();
            
            vector<int> pairSum(n-1, 0);
            
            for(int i = 0; i<n-1; i++) {
                pairSum[i] = weights[i] + weights[i+1];
            }
            
            sort(begin(pairSum), end(pairSum));
            long maxSum = 0;
            long minSum = 0;
            
            for(int i = 0; i<k-1; i++) {
                minSum += pairSum[i];
                maxSum += pairSum[n-i-2];
            }
            
            return maxSum-minSum;
        }
    };



    /*
    Algorithm explanation:
    1. Create a vector `pairSum` of size `n-1` to store the sum of adjacent weights.
    2. Iterate through the `weights` vector and calculate the sum of adjacent weights, storing them in `pairSum`.
    3. Sort the `pairSum` vector in ascending order.
    4. Initialize `maxSum` and `minSum` to 0.
    5. Iterate through the first `k-1` elements of `pairSum` to calculate `minSum`.
    6. Iterate through the last `k-1` elements of `pairSum` to calculate `maxSum`.
    7. Return the difference between `maxSum` and `minSum`.
    8. The result is the maximum difference between the sum of weights in the bags after putting marbles in them.
    */