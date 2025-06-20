// leetcode problem : https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/


class Solution {
public:
    int maxDistance(string s, int k) {
        int maxMD = 0;

        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;
            else if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;

            int currMD = abs(east-west) + abs(north-south);

            int steps  = i+1;
            int wasted = steps - currMD;

            int extra = 0;
            if(wasted != 0) { //steps != currMD
                extra = min(2*k, wasted);
            }

            int finalCurrentMD = currMD + extra;

            maxMD = max(maxMD, finalCurrentMD);
        }

        return maxMD;
    }
};


/*
Algorithm Explanation:
1. Initialize variables to keep track of the counts of each direction (east, west, north, south) and the maximum Manhattan distance (maxMD). 
2. Iterate through each character in the string `s`:
   - Update the counts based on the direction represented by the character.
   - Calculate the current Manhattan distance (currMD) using the formula: `abs(east - west) + abs(north - south)`.
   - Determine the number of steps taken so far (steps) and how many steps are wasted (wasted).
   - If there are wasted steps, calculate how many extra steps can be added using `min(2*k, wasted)`.
   - Update the final current Manhattan distance (finalCurrentMD) by adding the extra steps to currMD.
   - Update maxMD if finalCurrentMD is greater than the current maxMD.
3. Return the maximum Manhattan distance found (maxMD).
4. The algorithm runs in O(n) time complexity, where n is the length of the string `s`, making it efficient for large inputs.
*/