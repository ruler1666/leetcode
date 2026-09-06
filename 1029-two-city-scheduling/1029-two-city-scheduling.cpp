class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,vector<int>>>arr;
        int n=costs.size()/2;
        int cost=0;
        for(int i=0;i<costs.size();i++){
            int k=costs[i][0]-costs[i][1];
            arr.push_back({k,costs[i]});
        }

        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++){
            cost+= arr[i].second[0];
        }
        for(int i=n;i<2*n;i++){
            cost+= arr[i].second[1];
        }

        return cost;
    }
};

