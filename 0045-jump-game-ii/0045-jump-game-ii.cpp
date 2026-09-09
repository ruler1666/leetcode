class Solution {
public:
    int jump(vector<int>& nums) {
        int low=0;
        int high=0;
        int count=0;

        while(high < nums.size()-1){
            int maxi=0;

            for(int i=low;i<=high;i++){
                maxi=max(maxi,i+nums[i]);
            }
            low=high+1;
            high=maxi;
            count++;
        }
        return count;
    }
};