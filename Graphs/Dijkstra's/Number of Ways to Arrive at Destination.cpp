//leetcode problem : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/?envType=daily-question&envId=2025-03-23

class Solution {
    public:
        typedef pair<long long, int> P;
        const int M = 1e9 + 7;
        int countPaths(int n, vector<vector<int>>& roads) {
            unordered_map<int, vector<pair<int, int>>> adj;
            for (auto &road : roads) {
                int u    = road[0];
                int v    = road[1];
                int time = road[2];
                adj[u].push_back({v, time});
                adj[v].push_back({u, time});
            }
    
            priority_queue<P, vector<P>, greater<P>> pq;
            vector<long long> result(n, LLONG_MAX);
            vector<int> pathCount(n, 0);
            result[0] = 0;
            pathCount[0] = 1;
            pq.push({0, 0});
            while (!pq.empty()) {
                long long currTime = pq.top().first;
                int currNode       = pq.top().second;
                pq.pop();
                for (auto &vec : adj[currNode]) {
                    int adjNode  = vec.first;
                    int roadTime = vec.second;
                    if (currTime + roadTime < result[adjNode]) {
                        result[adjNode] = currTime + roadTime;
                        pathCount[adjNode] = pathCount[currNode];
                        pq.push({result[adjNode], adjNode});
                    } else if (currTime + roadTime == result[adjNode]) {
                        pathCount[adjNode] = (pathCount[adjNode] + pathCount[currNode]) % M;
                    }
                }
            }        
            return pathCount[n - 1];
        }
    };


    /*
    Algorithm Explanation:
    1. We create an adjacency list `adj` to represent the roads between cities.
    2. We initialize a priority queue `pq` to perform Dijkstra's algorithm.
    3. We maintain a `result` vector to store the shortest time to reach each city and a `pathCount` vector to count the number of ways to reach each city.
    4. We set the time to reach the starting city (city 0) to 0 and the number of ways to reach it to 1.
    5. We push the starting city into the priority queue.
    6. While the priority queue is not empty, we pop the city with the smallest time.
    7. For each adjacent city, we check if the current time plus the road time is less than the recorded time for that city.
    8. If it is, we update the time and the number of ways to reach that city.
    9. If the time is equal, we add the number of ways from the current city to the adjacent city.
    10. Finally, we return the number of ways to reach the destination city (city n-1).
    11. The result is taken modulo 1e9 + 7 to prevent overflow.
    
    */