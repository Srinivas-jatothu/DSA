// leetcode problem : https://leetcode.com/problems/reverse-vowels-of-a-string/description/

class Solution {
public:
    bool isVowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'  ){
            return true;
           }

           return false;
    }
    string reverseVowels(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;

        while(i<j){
            if(!isVowel(s[i])){
                i++;
            }
            else if(!isVowel(s[j])){
                j--;
            }
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};



/*
Algorithm Explanation:
1. Define a helper function `isVowel` that checks if a character is a vowel (both uppercase and lowercase).
2. In the `reverseVowels` function, initialize two pointers: `i` at the start of the string and `j` at the end.
3. Use a while loop to iterate until the two pointers meet:
   - If the character at pointer `i` is not a vowel, increment `i`.
   - If the character at pointer `j` is not a vowel, decrement `j`.
   - If both characters are vowels, swap them and move both pointers inward.
4. Return the modified string after all vowels have been reversed.
Time Complexity: O(n), where n is the length of the string, as we traverse the string once.
Space Complexity: O(1), as we are modifying the string in place without using extra space
*/