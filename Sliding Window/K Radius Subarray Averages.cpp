// leetcode problem : https://leetcode.com/problems/k-radius-subarray-averages/description/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res(n,-1);
        if(k==0) return nums;
        if(n<2*k+1) return res;
        long long window_sum=0;
        int left=0;
        int right=2*k;
        int i=k;
        for( int i=0;i<=right;i++){
            window_sum+=nums[i];
        }
        res[i]=(window_sum)/(2*k+1);
        i++;
        right++;
        while(right<n){
            int out_of_window  = nums[left];
            int came_to_window = nums[right];            
            window_sum = window_sum - out_of_window + came_to_window;            
            res[i] = window_sum/(2*k+1);
            i++;
            left++;
            right++;
        } 
        return res;   
    }
};


/*
Algorithm Explanation:
1. Initialize the size of the input vector `nums` as `n` and create a result vector `res` of size `n` filled with -1.
2. If `k` is 0, return the original vector `nums` since no averaging is needed.
3. If the size of `nums` is less than `2*k + 1`,
   return the result vector `res` since there are not enough elements to form a valid average.
4. Initialize a variable `window_sum` to store the sum of the current window, and two pointers `left` and `right` to represent the bounds of the window.
5. Calculate the initial sum of the first `2*k + 1` elements and store it in `window_sum`.
6. Set the average for the first valid index `i = k` in the result vector `res` by dividing `window_sum` by `2*k + 1`.
7. Increment `i` and `right` to move to the next index.
8. Use a while loop to slide the window across the vector:
   - For each iteration, subtract the element that is going out of the window (`out_of_window`) and add the new element that is coming into the window (`came_to_window`).
   - Update `window_sum` accordingly.
   - Calculate the average for the current index `i` and store it in `res`.
   - Increment `i`, `left`, and `right` to move the window forward.
9. After processing all elements, return the result vector `res` containing the averages.
// Time Complexity: O(n), where n is the number of elements in the input vector `nums`.
*/