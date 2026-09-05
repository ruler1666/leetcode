class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,vector<int>>mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }

        vector<pair<int,int>>arr;
        for(auto s :mp){
            arr.push_back({s.second[0],s.second.back()});
        }

        sort(arr.begin(),arr.end());
        int maxi=0;
        vector<int>ans;
        int start=0;

        for(int i=0;i<arr.size();i++){
            maxi=arr[i].second;
            int j=i+1;

            while(j<arr.size() && arr[j].first <maxi){
                maxi = max(maxi,arr[j].second);
                j++;
            }

            ans.push_back(maxi-start+1);
            start=maxi+1;
            i=j-1;
        }

        return ans;
    }
};