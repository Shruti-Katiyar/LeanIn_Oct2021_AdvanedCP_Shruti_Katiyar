//Topological sort
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        for(auto nbr:adj[i]){
	            indegree[nbr]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	      int node=q.front();
	      q.pop();
	      ans.push_back(node);
	      for(auto nbr:adj[node]){
	          indegree[nbr]--;
	          if(indegree[nbr]==0){
	              q.push(nbr);
	          }
	      }
	    } 
	    
	   return ans;     
	    
	}
};
