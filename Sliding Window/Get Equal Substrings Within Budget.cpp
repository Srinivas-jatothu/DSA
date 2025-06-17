// leetcode problem : https://leetcode.com/problems/get-equal-substrings-within-budget/description/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int i=0;
        int j=0;
        int max_length=0;
        int cost=0;

        while(j<n){
            cost+=abs(s[j]-t[j]);
            while(i<n && cost>maxCost){
                cost-=abs(s[i]-t[i]);
                i++;
            }
            max_length=max(max_length,j-i+1);
            j++;
        }
        return max_length;
    }
};


/*
Algorithm Explanation:
1. Initialize two pointers `i` and `j` to represent the start and end of the sliding window.
2. Use a variable `cost` to keep track of the total cost of changing characters from string `s` to string `t` within the current window.
3. Iterate through the string with pointer `j`:
   - Add the cost of changing the character at position `j` from `s[j]` to `t[j]` to the `cost`.
   - If the `cost` exceeds `maxCost`, increment pointer `i` to shrink the window from the left until the `cost` is within the budget.
   - Update `max_length` with the maximum length of the valid substring found so far.
4. Return `max_length` as the result.
Time Complexity: O(n), where n is the length of the strings.
*/