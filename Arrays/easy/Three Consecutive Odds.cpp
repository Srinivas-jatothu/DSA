// leetcode problem: https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2025-05-11

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();        
        for(int i = 0; i < n-2; i++) {
            if(arr[i]%2 && arr[i+1]%2 && arr[i+2]%2) {
                return true;
            }
        }
        return false;
    }
};

/*
Algorithm Explanation:
1. Initialize a variable `n` to store the size of the input array `arr`.
2. Iterate through the array from index 0 to `n-2`.
3. For each index `i`, check if the current element and the next two elements are odd.
4. If all three elements are odd, return true.
5. If the loop completes without finding three consecutive odd numbers, return false.
6. The time complexity of this solution is O(n), where n is the length of the input array.
7. The space complexity is O(1) since we are using a constant amount of extra space.
*/