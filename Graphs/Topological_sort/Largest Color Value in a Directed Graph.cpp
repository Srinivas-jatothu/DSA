// leetcode problem : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/?envType=daily-question&envId=2025-05-26

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int N = colors.size();
        
        vector<int> indegree(N, 0);
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            indegree[v]++;
            
        }
        
        queue<int> que;
        vector<vector<int>> t(N, vector<int>(26, 0));
        
        for(int i = 0; i<N; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                t[i][colors[i]-'a'] = 1;
            }
        }
        
        int answer = 0;
        
        int countNodes = 0;
        
        while(!que.empty()) {
            
            int u = que.front();
            que.pop();
            
            countNodes++;
            
            answer = max(answer, t[u][colors[u]-'a']);
            
            for(int &v : adj[u]) {
                
                for(int i = 0; i<26; i++) {
                    
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v]-'a' == i));
                    
                }
                
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
            
        }
        
        if(countNodes < N)
            return -1;
        
        return answer;
    }
};



/*
Algorithm explanation:
1. Initialize an adjacency list `adj` to represent the directed graph and an integer `N` to store the number of nodes (colors).
2. Create a vector `indegree` to keep track of the indegree of each node (number of incoming edges).
3. Populate the adjacency list and indegree vector by iterating through the `edges` vector.
4. Initialize a queue `que` to perform a topological sort and a 2D vector `t` to store the maximum color values for each node.
5. Push all nodes with an indegree of 0 into the queue and initialize their color count in `t`.
6. Initialize an integer `answer` to keep track of the maximum color value found and a counter `countNodes` to count the number of processed nodes.
7. While the queue is not empty:
   - Pop a node `u` from the queue.
   - Increment `countNodes`.
   - Update `answer` with the maximum color value for node `u`.
   - For each neighbor `v` of node `u`:
     - Update the color counts in `t[v]` based on the color counts from `t[u]`.
     - Decrement the indegree of `v`. If it becomes 0, push `v` into the queue.
8. After processing all nodes, check if `countNodes` is less than `N`. If so, return -1 (indicating a cycle).
9. Finally, return `answer`, which represents the largest color value in the directed graph.
Time complexity: O(N + E), where N is the number of nodes and E is the number of edges in the graph.
*/