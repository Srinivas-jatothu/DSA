// leetcode problem : https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/?envType=daily-question&envId=2025-05-30

class Solution {
public:
    int n;
    
    void dfs(vector<int>& edges, int startNode, vector<int>& dist_node, vector<bool>& visited) {
        visited[startNode] = true;
        
        int v = edges[startNode];
        
        if(v != -1 && !visited[v]) {
            visited[v] = true;
            dist_node[v] = 1 + dist_node[startNode];
            dfs(edges, v, dist_node, visited);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);
        
        
        int minDistNode    = -1;
        int minDistTillNow = INT_MAX;
        for (int i = 0; i < n; i++) {
            
            int maxD = max(dist1[i], dist2[i]);
            
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
        
    }
};


/*
Algorithm Explanation:
1. **Initialization**: 
   - The function `closestMeetingNode` initializes the size of the edges vector `n`, and creates distance vectors `dist1` and `dist2` initialized to `INT_MAX`, which will hold the distances from `node1` and `node2` respectively.
   - Two boolean vectors `visited1` and `visited2` are also initialized to keep track of visited nodes during DFS.
2. **DFS Traversal**:
    - The `dfs` function performs a depth-first search starting from a given node. It marks the current node as visited and updates the distance for the next node in the path.
    - If the next node is valid (not -1) and not visited, it recursively calls itself on that node.
3. **Finding Closest Meeting Node**:
    - After performing DFS from both `node1` and `node2`, the function iterates through all nodes to find the one with the minimum maximum distance from both starting nodes.
    - It keeps track of the node with the smallest maximum distance and returns it.
4. **Return Value**:
    - The function returns the index of the closest meeting node, which is the node that minimizes the maximum distance from both `node1` and `node2`.
5. **Time Complexity**:
    - The time complexity of this algorithm is O(n), where n is the number of nodes in the graph, as each node and edge is processed once during the DFS traversal.
*/