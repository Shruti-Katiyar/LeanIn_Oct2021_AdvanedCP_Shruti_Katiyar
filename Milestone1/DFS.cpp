//DFS of Graph 
class Solution {
public:
    vector<int> ans;
    void dfshelper(int node,vector<int> &visited,vector<int> adj[]){
        visited[node]=1;
        ans.push_back(node);
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                dfshelper(nbr,visited,adj);
            }
        }
    }
    
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	 
	  vector<int>visited(V,0);
	  dfshelper(0,visited,adj);
	  return ans ;
	}
};
