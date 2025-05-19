// leetcode problem: https://leetcode.com/problems/type-of-triangle/description/?envType=daily-question&envId=2025-05-19

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums.size() != 3) {
            return "none";
        }
        sort(nums.begin(), nums.end()); 
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        } else {
              return "scalene";
        }
    }
};


/*
Algorithm explanation:
1. Check if the input vector has exactly 3 elements. If not, return "none".
2. Sort the vector in ascending order to simplify the triangle inequality check.
3. Check the triangle inequality: if the sum of the two smaller sides is less than or equal to the largest side, return "none".
4. Check for equilateral triangle: if all three sides are equal, return "equilateral".
5. Check for isosceles triangle: if any two sides are equal, return "isosceles".
6. If none of the above conditions are met, return "scalene" for a triangle with all sides of different lengths.
*/