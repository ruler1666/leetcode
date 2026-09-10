class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>>arr;

        for(int i=0;i<ranges.size();i++){
            arr.push_back({i-ranges[i],i+ranges[i]});
        }

        sort(arr.begin(),arr.end());

        int current=0;
        int farthest=0;
        int count=0;

        for(int i=0;i<arr.size();i++){
            int j=i;
            while(j<arr.size() && arr[j][0]<=current){
                farthest=max(farthest, arr[j][1]);
                j++;
            }
            if(farthest==current)return -1;
            current=farthest;
            count++;

            if(current>=n)return count;
            i=j-1;
        }
        return -1;
    }
};