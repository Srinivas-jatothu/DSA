// leetcode problem : https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2025-06-02https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2025-06-02

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> L2R(n, 1);
        vector<int> R2L(n, 1);
        
        //First comparing with only left neighbour
        for(int i = 1; i<n; i++) {
            if(ratings[i] > ratings[i-1])
                L2R[i] = max(L2R[i], L2R[i-1]+1);
        }
        
        //Then comparing with only right neighbour
        for(int i = n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1])
                R2L[i] = max(R2L[i], R2L[i+1]+1);
        }
        
        
        int result = 0;
        for(int i = 0; i<n; i++) {
            result += max(L2R[i], R2L[i]);
        }
        
        return result;
    }
};

/*
Algorithm Explanation:
1. **Understanding the Problem**: We need to distribute candies to children based on their ratings such that:
   - Each child gets at least one candy.
   - A child with a higher rating than their neighbor must receive more candies than that neighbor.
2. **Two-Pass Approach**:
    - **Left to Right Pass**: We traverse the ratings from left to right. If a child has a higher rating than the previous child, we increase their candy count based on the previous child's count.
    - **Right to Left Pass**: We traverse the ratings from right to left. If a child has a higher rating than the next child, we ensure they have more candies than that child.
3. **Combining Results**: After both passes, we take the maximum of the candies assigned in both directions for each child to ensure all conditions are met.
4. **Final Count**: We sum up the candies assigned to each child to get the total number of candies needed.
5. **Return Result**: Finally, we return the total count of candies.

*/