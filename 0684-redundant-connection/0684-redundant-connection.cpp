class Solution {
public:
    vector<int>parent;
    int find(int a){
        if(parent[a]==a)return a;
        
        return parent[a]=find(parent[a]);
    }

    void unite(int u,int v){
       u = find(u);
    v = find(v);

    if(u != v){
        parent[v] = u;
    }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n + 1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            if(find(u)==find(v)){
                return edges[i];
            }

            unite(u,v);
        }
        return {};
    }
};