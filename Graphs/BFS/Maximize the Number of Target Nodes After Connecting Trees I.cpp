// leetcode problem : https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/?envType=daily-question&envId=2025-05-28

class Solution {
public:

    int dfs(int curr, unordered_map<int, vector<int>>& adj, int d, int currNodeKaParent) {
        if(d < 0)
            return 0;
        
        int count = 1; //counting current node as 1

        for(int &ngbr : adj[curr]) {
            if(ngbr != currNodeKaParent) {
                count += dfs(ngbr, adj, d-1, curr);
            }
        }

        return count;
    }

    vector<int> findCount(vector<vector<int>>& edges, int d) {
        int N = edges.size()+1;

        //adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(N);
        for(int i = 0; i < N; i++) {
            result[i] = dfs(i, adj, d, -1);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int N = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k); 
        vector<int> result2 = findCount(edges2, k-1); 

        int maxTargetNodesCount = *max_element(begin(result2), end(result2));
        
        for(int i = 0; i < result1.size(); i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
};


/*
Algorithm Explanation:
1. The `maxTargetNodes` function takes two edges lists (`edges1` and `edges2`) and an integer `k` as input.
2. It calculates the number of target nodes for each node in the first tree using the `findCount` function with depth `k`.
3. The `findCount` function constructs an adjacency list from the edges and performs a depth-first search (DFS) to count the number of nodes reachable within the given depth `d`.
4. The DFS function `dfs` recursively counts the nodes reachable from the current node, excluding the parent node to avoid cycles.
5. The results from the first tree are stored in `result1`.
6. The function then calculates the maximum number of target nodes from the second tree using `findCount` with depth `k-1`.
7. The maximum count from the second tree is added to each count in `result1`.
8. Finally, the function returns the modified `result1` which contains the total count of target nodes for each node in the first tree after considering the second tree.
9. The time complexity is O(N) for each tree, where N is the number of nodes in the tree.
*/