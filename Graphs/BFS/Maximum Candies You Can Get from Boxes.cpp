// leetcode problem : https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/?envType=daily-question&envId=2025-06-03https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/?envType=daily-question&envId=2025-06-03

class Solution {
public:

    int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>& visited, unordered_set<int>& foundBoxes) {
        
        if(visited.count(box)) {
            return 0;
        }

        if(status[box] == 0) {
            foundBoxes.insert(box);
            return 0;
        }

        visited.insert(box);
        int candiesCollected = candies[box];


        for(int &insideBox : containedBoxes[box]) {
            candiesCollected += dfs(insideBox, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        for(int &boxKey : keys[box]) {
            status[boxKey] = 1; //can be opened
            if(foundBoxes.count(boxKey)) {
                candiesCollected += dfs(boxKey, status, candies, keys, containedBoxes, visited, foundBoxes);
            }
        }

        return candiesCollected;

    }

    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int candiesCollected = 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;
        //T.C : O(n) visiting all box only once , n = number of boxes
        //S.C : O(n)
        for(int &box : initialBoxes) {
            candiesCollected += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        return candiesCollected;
    }
};

/*
Algorithm Explanation:
1. **Understanding the Problem**: We need to collect candies from boxes, some of which are locked and require keys to open. We can only open boxes that are either initially available or for which we have found keys.
2. **Depth-First Search (DFS)**: We use DFS to explore each box:
   - If a box is already visited, we skip it.
   - If a box is locked and we don't have the key, we skip it.
   - If a box is open, we collect its candies and explore the boxes inside it.
   - We also check for keys in the current box and unlock any boxes that can be opened with those keys.
3. **Tracking State**: We maintain a set of visited boxes to avoid cycles and a set of found boxes to track which boxes can be opened.
4. **Collecting Candies**: As we explore each box, we accumulate the candies collected from all accessible boxes.
5. **Return Result**: Finally, we return the total number of candies collected from all accessible boxes.
6. **Complexity**: The time complexity is O(n) where n is the number of boxes, as each box is visited only once. The space complexity is also O(n) due to the use of sets for tracking visited and found boxes.
*/
