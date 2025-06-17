//leetcode problem : https://leetcode.com/problems/subarray-product-less-than-k/description/


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        int count=0;
        int n=nums.size();
        if(k<=1){
            return 0;
        }

        int product=1;

        while(j<n){
            product*=nums[j];
            while(product>=k){
                product/=nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
};

/*
Algorithm Explanation:
1. Initialize two pointers `i` and `j` to 0, and a variable `count` to keep track of the number of valid subarrays found. Also, initialize `n` as the size of the input vector `nums`.
2. If `k` is less than or equal to 1, return 0 since no subarray product can be less than `k` in that case.
3. Initialize a variable `product` to 1 to keep track of the product of the current subarray.
4. Use a while loop to iterate through the array with the `j` pointer:
   - Multiply `product` by the current element `nums[j]`.
   - While `product` is greater than or equal to `k`, divide `product` by the element at index `i` and increment `i` to shrink the window from the left.
   - Add the number of valid subarrays ending at index `j` to `count`, which is given by `(j - i + 1)`.
   - Increment `j` to expand the window to the right.
5. After the loop, return `count`, which contains the total number of subarrays whose product is less than `k`.
Time Complexity: O(n), where n is the number of elements in the input vector `nums
*/