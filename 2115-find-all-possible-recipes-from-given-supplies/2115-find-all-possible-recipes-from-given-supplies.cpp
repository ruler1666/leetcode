class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
       
        unordered_map<string,int>mp1,mp2;
        vector<int>indegree(n);
        vector<vector<int>>graph(n);

        for(auto k:supplies ){ mp1[k]++;}
        for(int i=0;i<recipes.size();i++){
            mp2[recipes[i]]=i;
        }


      for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(mp1.count(ingredients[i][j]))continue;

                if(mp2.count(ingredients[i][j])){
                   int k=mp2[ingredients[i][j]];
                   graph[k].push_back(i);
                   indegree[i]++;
                }else{
                    indegree[i]++;
                }
            }
    }

      

        queue<int>q;
        vector<string>ans;

        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }

        while(!q.empty()){
            int k=q.front();
            q.pop();
            ans.push_back(recipes[k]);

            for(int i=0;i<graph[k].size();i++){
                indegree[graph[k][i]]--;

                if(indegree[graph[k][i]]==0){
                    q.push(graph[k][i]);
                }
            }

        }

        return ans;

    }
};