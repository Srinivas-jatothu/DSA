// leetcode problem : https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/?envType=daily-question&envId=2025-06-04

class Solution {
public:
    int bestStartingPoint(string &word, int n) {
        int i = 0; //best starting point
        int j = 1; //keep moving to find the best starting point

        while(j < n) {
            int k = 0;

            //skipping equal characters
            while( j+k < n && word[i+k] == word[j+k]) {
                k++;
            }

            if(j+k < n && word[j+k] > word[i+k]) {
                i = j; //updating best starting point
                j = j+1;
            } else {
                j = j + k + 1; //skipping already checked characters
            }
        }

        return i;
    }

    string answerString(string word, int numFriends) {
        int n = word.length();

        if(numFriends == 1)
            return word;

        int i = bestStartingPoint(word, n);

        int longestPossibleLength = n - (numFriends-1);
        int canTakePossible       = min(longestPossibleLength, n-i);

        return word.substr(i, canTakePossible);

    }
};


/*
Algorithm Explanation:
1. The answerString function takes a string word and an integer numFriends as input.
2. It calculates the length of the string word and checks if numFriends is 1. If so, it returns the original string.
3. It calls the bestStartingPoint function to find the best starting point in the string word.
4. The bestStartingPoint function uses a two-pointer technique to find the lexicographically largest starting point in the string.
5. It initializes two pointers i and j, where i is the best starting point and j is used to find the next potential starting point.
6. It iterates through the string, comparing characters at positions i and j, and updates the best starting point accordingly.
7. Finally, it calculates the longest possible length of the substring that can be taken based on the number of friends and returns the substring starting from the best starting point with the calculated length.
8. The answerString function returns the final substring that can be shared among friends.
9. The time complexity of the solution is O(n), where n is the length of the string word, as it processes each character at most twice.
*/