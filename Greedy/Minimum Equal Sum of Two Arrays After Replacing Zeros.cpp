// leetcode problem : https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/?envType=daily-question&envId=2025-05-10

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        long long zero1 = 0;
        long long zero2 = 0;

        for(int &num : nums1) {
            sum1 += num;
            if(num == 0) { 
                zero1 += 1;
                sum1 += 1;
            }
        }

        for(int &num : nums2) {
            sum2 += num;
            if(num == 0) { 
                zero2 += 1;
                sum2 += 1;
            }
        }

        if((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0)) {
          return -1;
        }
        
        return max(sum1, sum2);
    }
};


/*
Algorithm Explanation:
1. Initialize two variables `sum1` and `sum2` to store the sum of elements in `nums1` and `nums2`, respectively.
2. Initialize two variables `zero1` and `zero2` to count the number of zeros in `nums1` and `nums2`, respectively.
3. Iterate through `nums1` and `nums2`, updating the sums and counts of zeros.
4. If the sum of one array is less than the other and there are no zeros in that array, return -1.
5. Otherwise, return the maximum of the two sums.
6. The time complexity of this solution is O(n), where n is the length of the input arrays.
*/