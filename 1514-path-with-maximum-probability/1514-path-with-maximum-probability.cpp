class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>graph(n);

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double>prob(n,0.0);

        priority_queue<pair<double,int>>pq;
        prob[start_node]=1.0;
        pq.push({1.0,start_node});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            double maxip = it.first;
            int source =it.second;

            if(maxip < prob[source])continue;

            if(source==end_node)return maxip;
            
            for(int i=0;i<graph[source].size();i++){
                double newmaxi = maxip *graph[source][i].second;

                if(newmaxi > prob[graph[source][i].first]){
                    prob[graph[source][i].first]=newmaxi;
                    pq.push({newmaxi,graph[source][i].first});
                }
            }
        }
        return 0;
    }
};