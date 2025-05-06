// leetcode problem : https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06


class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n=nums.size();
            for(int i=0;i<n;i++){
                nums[i]=nums[i]+(n*(nums[nums[i]]%n));
            }
            for(int i=0;i<n;i++){
                nums[i]/=n;
            }
            return nums;
        }
    };



    /*
    Algorithm Explanation:
    1. The function `buildArray` takes a vector of integers `nums` as input.
    2. It calculates the size of the input vector `n`.
    3. It iterates through each element of the vector `nums` using a for loop.
    4. For each element at index `i`, it updates the value of `nums[i]` to be the sum of its original value and the product of `n` and the value at the index specified by `nums[i]` modulo `n`. This step effectively encodes both the original value and the new value in a single integer.
    5. After the first loop, each element in `nums` contains both the original value and the new value encoded in it.
    6. The second loop iterates through the vector again, this time dividing each element by `n` to extract the new value.
    7. Finally, the function returns the modified vector `nums`, which now contains the new values as specified by the problem statement.
    8. The time complexity of this algorithm is O(n), where n is the size of the input vector, as it iterates through the vector twice.
    */