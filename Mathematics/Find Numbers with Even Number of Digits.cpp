// leetcode problem : https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/?envType=daily-question&envId=2025-04-30

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count=0;
            for(int i=0;i<nums.size();i++){
                if((int)(log10(abs(nums[i])) + 1) %2 ==0){
                    count++;
                }
            }
            return count;
        }
    };



    /*
    Algorithm Explanation:
    1. Create a function `findNumbers` that takes a vector of integers `nums` as input.
    2. Initialize a variable `count` to 0, which will store the count of numbers with an even number of digits.
    3. Use a for loop to iterate through each element in the input array `nums`.
    4. For each element `nums[i]`, calculate the number of digits using the formula `log10(abs(nums[i])) + 1`.
    5. Check if the number of digits is even by using the modulo operator `%` with 2.
    6. If the number of digits is even, increment `count` by 1.
    7. After the loop, return `count` as the final count of numbers with an even number of digits.
    8. The time complexity of this algorithm is O(n), where n is the size of the input array `nums`, as we are iterating through the array once.
    9. The space complexity is O(1) as we are using a constant amount of extra space.
    */