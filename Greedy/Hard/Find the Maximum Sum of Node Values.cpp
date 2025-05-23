// leetcode problem : https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-question&envId=2025-05-23

class Solution {
public:
    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll  sum        = 0;
        int count      = 0;
        int minNukasan = INT_MAX;

        for (ll num : nums) {

            if((num^k) > num) {
                count++;
                sum += (num^k);
            } else {
                sum += num;
            }

            minNukasan = min((long long)minNukasan, abs(num - (num ^ k)));
        }

        if(count%2 == 0)
            return sum;

        return sum - minNukasan;
    }
};


/*
Algorithm explanation:
1. Initialize `sum` to 0, `count` to 0, and `minNukasan` to the maximum integer value.
2. Iterate through each element in the `nums` array.
3. For each element, check if the XOR of the element with `k` is greater than the element itself.
4. If it is, increment `count` and add the XOR value to `sum`.
5. If not, add the element itself to `sum`.
6. Update `minNukasan` to the minimum of its current value and the absolute difference between the element and its XOR with `k`.
7. After processing all elements, check if `count` is even.
8. If it is, return `sum` as is.
9. If `count` is odd, subtract `minNukasan` from `sum` and return the result.
10. The time complexity is O(n), where n is the size of the `nums` array.
*/