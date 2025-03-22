// Leetcode Problem :https://leetcode.com/problems/count-the-number-of-complete-components/?envType=daily-question&envId=2025-03-22

class Solution {
    public:
        void bfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int& v, int &e) {
            queue<int> que;
            que.push(i);
            visited[i] = true;
            while(!que.empty()) {
                int curr = que.front();
                que.pop();
                v++;
                e += adj[curr].size();
                for(int &ngbr : adj[curr]) {
                    if(!visited[ngbr]) {
                        visited[ngbr] = true;
                        que.push(ngbr);
                    }
                }
            }
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            unordered_map<int, vector<int>> adj;
            int result = 0;
            for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            vector<bool> visited(n, false);
            for(int i = 0; i < n; i++) {
                if(visited[i] == true) {
                    continue;
                }
                int v = 0;
                int e = 0;
                bfs(i, adj, visited, v, e);
    
                if((v*(v-1)) == e) {
                    result++;
                }
            }
            return result;
        }
};


    /*
    Algorithm Explanation:
    1. We create an adjacency list `adj` to represent the graph.
    2. We iterate through the edges and populate the adjacency list.
    3. We maintain a `visited` vector to keep track of visited nodes.
    4. For each unvisited node, we perform a BFS to count the number of vertices `v` and edges `e` in the connected component.
    5. We check if the component is complete by verifying if `v*(v-1) == e`.
    6. If it is complete, we increment the result counter.
    7. Finally, we return the result counter which represents the number of complete components in the graph.
    */
