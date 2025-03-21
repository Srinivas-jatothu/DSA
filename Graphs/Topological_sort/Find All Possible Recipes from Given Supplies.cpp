// Leetcode Problem :https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/?envType=daily-question&envId=2025-03-21

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n = recipes.size();
            unordered_set<string> st(begin(supplies), end(supplies));
            unordered_map<string, vector<int>> adj; 
            vector<int> indegree(n, 0);
            for(int i = 0; i < n; i++) {
                for(string& ing : ingredients[i]) {
                    if(!st.count(ing)) {
                        adj[ing].push_back(i);
                        indegree[i]++;
                    }
                }
            }
    
            queue<int> que;
            for(int i = 0; i < n; i++) {
                if(indegree[i] == 0) {
                    que.push(i);
                }
            }
    
            vector<string> result;
            while(!que.empty()) {
                int i = que.front();
                que.pop();
                string recipe = recipes[i];
                result.push_back(recipe);
    
                for(int &idx : adj[recipe]) {
                    indegree[idx]--;
                    if(indegree[idx] == 0) {
                        que.push(idx);
                    }
                }
            }
    
            return result;
        }
    };

    /*
    Algorithm Explanation:
    1. We initialize a set `st` with the given supplies for O(1) lookups.
    2. We create an adjacency list `adj` to represent the dependencies of recipes on ingredients.
    3. We also maintain an `indegree` vector to count how many ingredients each recipe depends on.
    4. For each recipe, we iterate through its ingredients. If an ingredient is not in `st`, we add it to the adjacency list and increment the indegree of the recipe.
    5. We initialize a queue `que` with recipes that have no dependencies (indegree of 0).
    6. We perform a BFS: for each recipe in the queue, we add it to the result and decrease the indegree of its dependent recipes.
    7. If any dependent recipe's indegree becomes 0, we add it to the queue.
    8. Finally, we return the result vector containing all recipes that can be made with the given supplies.  
    */