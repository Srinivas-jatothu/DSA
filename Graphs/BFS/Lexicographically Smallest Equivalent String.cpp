// leetcode problem : https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/?envType=daily-question&envId=2025-06-05

class Solution {
public:
    
    char DFS(unordered_map<char, vector<char>> &adj, char curr, vector<int>& visited) {
        visited[curr-'a'] = 1;
        
        char minChar = curr;
        
        for(char &v : adj[curr]) {
            
            if(visited[v-'a'] == 0)
                minChar = min(minChar, DFS(adj, v, visited));
        }
        
        return minChar;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char, vector<char>> adj;
        
        for(int i = 0; i<n; i++) {
            char u = s1[i];
            char v = s2[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        int m = baseStr.length();
        string result;
        
        for(int i = 0; i<m; i++) {
            char ch = baseStr[i];
            
            vector<int> visited(26, 0);
            
            result.push_back(DFS(adj, ch, visited));
        }
        
        return result;
    }
};


/*
Algorithm Explanation:
1. The `smallestEquivalentString` function takes three strings: `s1`, `s2`, and `baseStr`.
2. It initializes an adjacency list `adj` to represent the equivalence relationships between characters in `s1` and `s2`.
3. For each character pair `(s1[i], s2[i])`, it adds both characters to each other's adjacency list, creating an undirected graph.
4. It then iterates through each character in `baseStr` and performs a depth-first search (DFS) to find the lexicographically smallest character that is equivalent to the current character.
5. The `DFS` function recursively explores the adjacency list, marking characters as visited and returning the smallest character found in the connected component.
6. The result is built by appending the smallest equivalent character for each character in `baseStr`.
7. Finally, the function returns the resulting string containing the smallest equivalent characters.
8. The time complexity of the solution is O(n + m), where n is the length of `s1` and `s2`, and m is the length of `baseStr`, as it processes each character in the strings and explores the adjacency list.
*/