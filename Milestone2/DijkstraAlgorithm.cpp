//Implementing Dijkstra Algorithm
class Solution
{
	public:
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      
  priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       pq.push({0,S});
       vector<int> ans(V,0);
       vector<bool> visit(V,false);
       while(!pq.empty()){
           auto p = pq.top();
           pq.pop();
           int x = p.second;
           int wt = p.first;
           if(visit[x])continue;
           visit[x] = true;
           ans[x] = wt;
           for(auto y:adj[x]){
               if(!visit[y[0]]) pq.push({wt + y[1],y[0]});
           }
       }
       return ans;
}
