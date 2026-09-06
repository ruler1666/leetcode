class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        vector<vector<int>>arr;
        for(int i=0;i<pairs.size();i++){
            arr.push_back({pairs[i][1],pairs[i][0]});
        }
        sort(arr.begin(), arr.end());

        int count=1;
        int i=0;
        int j=i+1;


       while(j<arr.size()){
            if(arr[i][0]<arr[j][1]){
                count++;
                i=j;
            }
            j++;
       }
       return count;
    }
};