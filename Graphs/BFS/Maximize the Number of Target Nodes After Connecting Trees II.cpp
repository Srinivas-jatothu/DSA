// leetcode problem : https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/?envType=daily-question&envId=2025-05-29

class Solution {
public:
    unordered_map<int, vector<int>> getAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent,
             vector<int>& mark, int& zeroMarkedCount, int& oneMarkedCount) {

        if (mark[curr] == 0) {
            zeroMarkedCount++;
        } else {
            oneMarkedCount++;
        }

        for (auto& ngbr : adj[curr]) {
            if (ngbr != parent) {
                mark[ngbr] = (mark[curr] == 0) ? 1 : 0; // alternate marking
                dfs(ngbr, adj, curr, mark, zeroMarkedCount, oneMarkedCount);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int N = edges1.size() + 1;
        int M = edges2.size() + 1;

        unordered_map<int, vector<int>> adjA = getAdj(edges1);

        unordered_map<int, vector<int>> adjB = getAdj(edges2);

        vector<int> markA(N, -1);
        markA[0] = 0;
        int zeroMarkedCountA = 0;
        int oneMarkedCountA = 0;
        dfs(0, adjA, -1, markA, zeroMarkedCountA, oneMarkedCountA);

        vector<int> markB(M, -1);
        markB[0] = 0;
        int zeroMarkedCountB = 0;
        int oneMarkedCountB = 0;
        dfs(0, adjB, -1, markB, zeroMarkedCountB, oneMarkedCountB);

        int maxFromTree2 = max(zeroMarkedCountB, oneMarkedCountB);

        vector<int> result(N);
        for (int i = 0; i < N; i++) { // O(V)
            result[i] = (markA[i] == 0 ? zeroMarkedCountA : oneMarkedCountA) +
                        maxFromTree2;
        }

        return result;
    }
};

/*
Algorithm Explanation:
1. The `maxTargetNodes` function takes two edges lists (`edges1` and `edges2`) as input.
2. It constructs adjacency lists for both trees using the `getAdj` function.
3. It performs a depth-first search (DFS) on the first tree to mark nodes and count how many nodes can be reached with two different markings (0 and 1).
4. It does the same for the second tree.
5. Finally, it calculates the maximum number of target nodes for each node in the first tree by adding the maximum count from the second tree to the count from the first tree based on the marking.
6. The result is returned as a vector of integers representing the maximum target nodes for each node in the first tree.
7. The time complexity is O(V + E) for each tree, where V is the number of vertices and E is the number of edges.
*/