//Distance from the Source (Bellman-Ford Algorithm) 

class Solution{
	public:
        vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> distance(V, 1e8);
        
        distance[S] = 0;
        
        for(int i = 0;i < V-1; i++)
        {
            for(auto &x : adj)
            {
                int u = x[0], v = x[1], wt = x[2];
                
                if(distance[u] + wt < distance[v])
                    distance[v] = distance[u] + wt;
            }
        }
        
        return distance;
    }
};


