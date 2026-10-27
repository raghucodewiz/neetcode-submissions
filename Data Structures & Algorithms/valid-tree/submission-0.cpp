class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        for(const auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);   
        }

        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({0, -1});
        visited.insert(0);

        while(!q.empty())
        {
            auto [node, parent] = q.front(); q.pop();
            for(int n : adj[node])
            {
                if(n == parent) continue;
                if(visited.count(n))
                    return false;
                visited.insert(n);
                q.push({n, node});
            }
        }

        return visited.size() == n;
    }
};
