class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int count=0;
        int ans=0;
        int n = truckSize;

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<boxTypes.size();i++ ){
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }

        while(!pq.empty() && n>0){
            int k=pq.top().second;
            int m=pq.top().first;

            while(k>0&&n>0){
                ans+=m;
                k--;
                n--;
            }
            pq.pop();
            
        }
        return ans;
    }
};