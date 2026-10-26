class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        numCourses=3
        prerequisites=[[1,0],[1,2],[0,1]]
        */
        vector<int> res;
        int n = numCourses;
        vector<int> indegree(n+1, 0);
        vector<vector<int>> adj(n+1);

        for(auto& pre: prerequisites)
        {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> msbfsQueue;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0) msbfsQueue.push(i);
        }

        while(!msbfsQueue.empty())
        {
            auto node = msbfsQueue.front(); msbfsQueue.pop();
            res.push_back(node);
            for(auto nodeNeighbour : adj[node])
            {
                indegree[nodeNeighbour]--;
                if(indegree[nodeNeighbour] == 0){
                    msbfsQueue.push(nodeNeighbour);
                }
            }
        }
        return res.size() == n ? res : vector<int>();
    }
};
