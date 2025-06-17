// leetcode problem : https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution {
public:
    bool check(vector<int>freq){
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n= s.size();
        int k=p.size();
        vector<int>res;
        vector<int>freq(26,0);
        //here we are updating the frequency
        for(int i=0;i<p.length();i++){
            freq[p[i]-'a']++;
        }
        int i=0,j=0;
        while(j<n){
            //first we decrease the freq of the s[i]
            freq[s[j]-'a']--;

            //check if the window size if equal to k
            if(j-i+1==k){
                //if so check if all values in freq is zero. if so push i in res.
                if(check(freq)){
                    res.push_back(i);
                }
                //we try to check for next elements. so we try to  increase the freq of S[i]
                freq[s[i]-'a']++;
                //move i
                i++;
            }
            j++;
        }
        return res;
    }
};


/*
Algorithm Explanation:
1. Initialize a frequency vector `freq` of size 26 (for each letter in the alphabet) to keep track of character counts.
2. Populate `freq` with the counts of characters in string `p`.
3. Use two pointers `i` and `j` to represent the current window in string `s`.
4. Iterate through string `s` with pointer `j`:
   - Decrease the frequency of the character at `s[j]`.
   - If the current window size (`j - i + 1`) equals the length of `p`, check if all values in `freq` are zero (indicating an anagram).
   - If they are, add the starting index `i` to the result vector `res`.
   - Before moving to the next character, increase the frequency of the character at `s[i]` and move `i` forward.
5. Continue this process until the end of string `s` is reached.
6. Return the result vector `res` containing all starting indices of anagrams of `p` in `s`.
7. Time Complexity: O(n + m), where n is the length of string `s` and m is the length of string `p`. This is because we traverse both strings once and maintain a fixed-size frequency array.
*/