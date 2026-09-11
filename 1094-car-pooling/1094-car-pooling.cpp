class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> arr;

        for(int i=0;i<trips.size();i++){
            arr.push_back({trips[i][1], trips[i][2], trips[i][0]});
        }

        sort(arr.begin(), arr.end());
        int count=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i<arr.size();i++){

            // Remove everyone whose trip has ended
            while(!pq.empty() && pq.top().first <= arr[i][0]){
                count -= pq.top().second;
                pq.pop();
            }
            count += arr[i][2];
            if(count > capacity) return false;
            // Store {drop-off, passengers}
            pq.push({arr[i][1], arr[i][2]});
        }

        return true;
    }
};