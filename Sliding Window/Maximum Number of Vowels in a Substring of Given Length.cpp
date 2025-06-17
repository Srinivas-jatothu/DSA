// leetcode problem : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution {
public:
    bool vowel(char &ch){
        return ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u';
    }
    int maxVowels(string s, int k) {
        int res=0;
        int n=s.length();
        int count=0;
        int i=0;
        int j=0;
        while(j<n){
            if(vowel(s[j])){
                count++;
            }
            if(j-i+1 == k){
                res=max(count,res);
                if(vowel(s[i])){
                    count--;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};


/*
Algorithm Explanation:
1. Define a helper function `vowel` to check if a character is a vowel.
2. Initialize variables `res` to store the maximum number of vowels found, `n` for the length of the string, `count` for the current count of vowels in the window, and two pointers `i` and `j` for the sliding window.
3. Use a while loop to iterate through the string with the `j` pointer.
4. For each character at index `j`, check if it is a vowel and increment the `count` if it is.
5. If the current window size (`j - i + 1`) equals `k`,
   - Update `res` with the maximum of `count` and `res`.
   - If the character at index `i` is a vowel, decrement the `count`.
   - Move the left pointer `i` to the right by incrementing it.
6. Increment the right pointer `j` to expand the window.
7. After the loop, return `res`, which contains the maximum number of vowels in any substring of length `k`.
Time Complexity: O(n), where n is the length of the string s.
*/