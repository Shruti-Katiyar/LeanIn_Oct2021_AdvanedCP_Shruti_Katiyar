//Detect cycle in an undirected graph 
class Solution {
  public:
    bool dfs(int node, int parent,vector<int> adj[],vector<bool> &visited){
        visited[node]=true;
        for(auto nbr: adj[node]){
            if(!visited[nbr]){
                if(dfs(nbr,node,adj,visited))
                return true;
            }
            else if(nbr!=parent){
                return true;
            }
        }
        
           return false;
       
    }
   
    bool isCycle(int V, vector<int> adj[]) {
    
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool f=dfs(i,-1,adj,visited);
                if(f)return true;
            }
        }
        return false;
    }
    
    
};
