class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(n);

        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));


        priority_queue<pair<int , pair<int,int>> , vector<pair<int, pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        dist[src][0]=0;
        pq.push({0,{src,0}});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int w=it.first;
            int source= it.second.first;
            int stops = it.second.second;

            if(source==dst)return w;
            if(stops==k+1)continue;
          

            for(int i=0;i<graph[source].size();i++){
                int newcost= w+graph[source][i].second;
                int newstops = stops + 1;

                if(newcost < dist[graph[source][i].first][newstops]){
                    dist[graph[source][i].first][newstops]=newcost;
                    pq.push({newcost,{graph[source][i].first,newstops}});
                }
            }

        }
        return -1;

    }
};