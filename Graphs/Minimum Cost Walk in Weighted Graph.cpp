// Leetcode Problem :https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/?envType=daily-question&envId=2025-03-20





class Solution {
    public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        parent[y]=x;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int>cost(n);

        for (int i=0;i<n;i++){
            parent[i]=i;
            cost[i]=-1;
        }

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];

            int parent_u=find(u);
            int parent_v=find(v);

            if(parent_u!=parent_v){
                cost[parent_u]&=cost[parent_v];
                Union(parent_u,parent_v);
            }
            cost[parent_u]&=w;
        }


        vector<int>result;
        for(auto&j :query){
            int s=j[0];
            int d=j[1];
            int p1=find(s);
            int p2=find(d);
            if(s==d){
                result.push_back(0);
            }
            else if(p1!=p2){
                result.push_back(-1);
            }
            else{
                result.push_back(cost[p1]);
            }
        }
        return result;
        
    }
};

/*
Algorithm Explanation:
1. Initialize `parent` to track connected components and `cost` to track associated properties.
2. For each edge, find the roots of the two nodes.
3. If they belong to different components, perform a union and update the `cost` using bitwise AND (`&=`).
4. For each query:
   - If nodes are in the same component, return the cost for that component.
   - If not in the same component, return `-1`.
   - If source and destination are the same, return `0`.
5. The algorithm uses Union-Find to efficiently manage components and track the property with bitwise operations.
*/
