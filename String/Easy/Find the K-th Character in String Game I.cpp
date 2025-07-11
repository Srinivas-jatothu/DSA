// leetcode problem : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/?envType=daily-question&envId=2025-07-03

class Solution {
public:
    char kthCharacter(int k) {
        vector<int>word;
        word.push_back(0);

        while(word.size()<k){
            int currsize=word.size();
            for(int i=0;i<currsize;i++){
                word.push_back((word[i]+1)%26);
            }
        }
        return 'a'+word[k-1];
    }
};



/*
Algorithm Explanation:
1. Initialize a vector `word` with the first character (0).
2. Use a while loop to generate characters until the size of `word` is at least `k`.
3. For each character in the current `word`, append the next character (incremented by 1 and wrapped around using modulo 26) to the `word` vector.
4. Finally, return the k-th character (adjusted for 0-based indexing) by accessing `word[k-1]` and converting it to a character by adding 'a'.
5. The function returns the k-th character in the sequence generated by the game.
// Time Complexity: O(k)
// Space Complexity: O(k)
*/