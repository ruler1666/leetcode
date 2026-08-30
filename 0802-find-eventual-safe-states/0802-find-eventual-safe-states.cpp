class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph, vector<bool>&visited,  vector<bool>&pathvisi,vector<bool>&allpaths){
        visited[node]=true;
        pathvisi[node]=true;

        for(int i=0;i<graph[node].size();i++){
            int k=graph[node][i];
            if(!visited[k]){
                if(dfs(k,graph,visited,pathvisi,allpaths)){
                   allpaths[node] = true; //means node is unsafe or there is cycle
                    return true;
                }
            }
            else if(pathvisi[k]){
                allpaths[node]=true;
                return true;
            }
        }
        pathvisi[node]=false;
        allpaths[node]=false;//no cycle detected or node is safe
        return false; 
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n);
        vector<bool>pathvisi(n);
        vector<bool>allpaths(n);
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(!visited[i]){
               allpaths[i]= dfs(i,graph,visited,pathvisi,allpaths);
            }
            if(allpaths[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};