class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);

        for(auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                bfs(adj, visit, i);
                res++;
            }
        }
        return res;
    }
    void bfs(vector<vector<int>>& adj, vector<bool>& visit, int start)
    {
        queue<int> q;
        q.push(start);
        visit[start] = true;

        while(!q.empty())
        {
            int node = q.front(); q.pop();
            for(auto nei : adj[node])
            {
                if(!visit[nei])
                {
                    visit[nei] = true;
                    q.push(nei);
                }
            }
        }
    }
};
