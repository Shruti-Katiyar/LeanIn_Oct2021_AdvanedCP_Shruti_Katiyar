//Bipartite Graph_
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	     vector<int>visited(V,-1);
    int i;
    for(i=0;i<V;i++)
    {
        if(visited[i] == -1)
        {
            if(!bfs(visited,adj,V,i))
            return false;
        }
    }
    return true;
	}
	bool bfs(vector<int> &visited, vector<int>adj[], int V, int src)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    while(!q.empty())
    {
        int v=q.front().first;
        int lvl=q.front().second;
        q.pop();
        if(visited[v] == -1)
        {
            visited[v]=lvl;
        }
        else
        {
            if(visited[v] != lvl)
            return false;
        }
        for(int i=0;i<adj[v].size();i++)
        {
            if(visited[adj[v][i]] == -1)
            q.push({adj[v][i], lvl +1});
        }
    }
    return true;
}

};
