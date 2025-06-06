// leetcode problem : https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/?envType=daily-question&envId=2025-06-06

class Solution {
public:
    string robotWithString(string s) {
       int n=s.length();
       vector<char>preprocessing(n);
       preprocessing[n-1]=s[n-1];
       for(int i=n-2;i>=0;i--){
        preprocessing[i]=min(s[i],preprocessing[i+1]);
       } 
       string t="";
       string paper="";
       int i=0;
       while(i<n){
        t.push_back(s[i]);
        char mini=(i+1 < n) ? preprocessing[i+1]: s[i];
        while(!t.empty()&& t.back()<=mini){
            paper+=t.back();
            t.pop_back();
        }
        i++;
       }
       while(!t.empty()){
        paper+=t.back();
            t.pop_back();
       }
        return paper;
    }
    
};


/*
Algorithm Explanation:
1. The `robotWithString` function takes a string `s` as input.
2. It initializes a vector `preprocessing` to store the minimum character from the current index to the end of the string.
3. It fills the `preprocessing` vector by iterating from the end of the string to the beginning, ensuring that each position contains the smallest character from that position to the end.
4. It initializes two strings: `t` to hold characters that the robot has picked up and `paper` to hold the final result.
5. It iterates through the string `s`, adding characters to `t` and checking if the last character in `t` can be added to `paper`.
6. If the last character in `t` is less than or equal to the minimum character from the next position (stored in `preprocessing`), it adds that character to `paper` and removes it from `t`.
7. This process continues until all characters in `s` have been processed, ensuring that `paper` contains the lexicographically smallest string possible.
8. Finally, it returns the `paper` string as the result.
9. The time complexity of the solution is O(n), where n is the length of the input string `s`, as it processes each character in the string exactly once.
*/