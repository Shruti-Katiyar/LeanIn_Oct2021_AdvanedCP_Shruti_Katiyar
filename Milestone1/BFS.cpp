//BFS of graph 
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> v;
        queue<int> q;
        
        q.push(0);
        vector<int> visited(V,0);
        visited[0]=1;
        
        while(!q.empty()){
            int  n =q.front();
            q.pop();
            v.push_back(n);
            for(auto nbr: adj[n]){;
               if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=1;
            }
         }
     }
       return v; 
    }
};
