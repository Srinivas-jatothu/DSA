// leetcode problem : https://leetcode.com/problems/find-the-original-typed-string-i/description/?envType=daily-question&envId=2025-07-01


class Solution {
public:
    int possibleStringCount(string word) {
        int n= word.length();
        int count=0;

        for(int i=1;i<n;i++){
            if(word[i-1]==word[i]){
                count++;
            }
        }

        return count+1;
    }
};



/*
Algorithm Explanation:
1. The function `possibleStringCount` takes a string `word` as input.
2. It initializes an integer `n` to the length of the `word`.
3. It initializes an integer `count` to 0, which will keep track of the number of pairs of adjacent characters that are the same.
4. It iterates through the string from the second character to the last character (index 1 to n-1).
5. For each character, it checks if the current character is the same as the previous character. If they are the same, it increments the `count` by 1.
6. After the loop, it returns `count + 1`, which accounts for the original string itself, as each pair of adjacent characters contributes to one possible original typed string.
Time Complexity: O(n), where n is the length of the string `word`, as we iterate through the string once.
Space Complexity: O(1), as we are using a constant amount of space for the variables `n` and `count`.
*/